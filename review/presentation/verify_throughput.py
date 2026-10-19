#!/usr/bin/env python3
"""Check source rows, plotted artists, saved frames and presentation links."""
import csv
from decimal import Decimal
import hashlib
import importlib.util
import io
import json
from pathlib import Path
import re

from PIL import Image, ImageChops, ImageStat

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / 'docs/images'
CACHE = ROOT / '.cache/presentation-review'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    spec = importlib.util.spec_from_file_location('render_throughput', ROOT / 'review/presentation/render_throughput.py')
    render = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(render)
    manifest = json.loads((OUT / 'throughput-data.json').read_text())
    assert sha(ROOT / manifest['source']) == manifest['source_sha256']
    assert sha(ROOT / manifest['generator']) == manifest['generator_sha256']
    with (ROOT / 'bench/results.csv').open(newline='') as stream:
        source = list(csv.DictReader(stream))
    assert len(source) == 22
    assert [{k: v for k, v in r.items() if k != 'ratio_recomputed'} for r in manifest['rows']] == source
    by_key = {(int(r['generation']), r['mode']): r for r in source}
    generations, rows = render.load_rows(ROOT / 'bench/results.csv')
    assert generations == list(range(11))
    for name, meta in manifest['outputs'].items():
        assert sha(OUT / name) == meta['sha256']
        assert (OUT / name).stat().st_size == meta['bytes']
    CACHE.mkdir(parents=True, exist_ok=True)
    inspected = []
    errors = []
    with Image.open(OUT / 'throughput.gif') as animation:
        assert animation.n_frames == 11 and animation.info['loop'] == 0
        for generation in generations:
            fig = render.draw(generations, rows, generation)
            upper, lower = fig.axes
            shown = list(range(generation + 1))
            # Validate the actual plotted arrays, not only a metadata copy.
            assert list(upper.lines[0].get_xdata()) == list(upper.lines[1].get_xdata()) == shown
            assert list(lower.lines[2].get_xdata()) == list(lower.lines[3].get_xdata()) == shown
            assert list(upper.lines[0].get_ydata()) == [float(by_key[g, 'decode']['lean1090_msg_s']) / 1000 for g in shown]
            assert list(upper.lines[1].get_ydata()) == [float(by_key[g, 'decode']['rs1090_msg_s']) / 1000 for g in shown]
            for mode, artist in [('decode', lower.lines[2]), ('cpr', lower.lines[3])]:
                expected = [float(Decimal(by_key[g, mode]['lean1090_msg_s']) / Decimal(by_key[g, mode]['rs1090_msg_s'])) for g in shown]
                assert list(artist.get_ydata()) == expected
            assert list(lower.lines[0].get_ydata()) == [1.1, 1.1]
            assert upper.get_ylim()[0] == lower.get_ylim()[0] == 0
            assert upper.get_xlim() == lower.get_xlim() == (-0.35, 10.45)
            buffer = io.BytesIO()
            fig.savefig(buffer, format='png', dpi=120, metadata={'Software': 'lean1090 render_throughput.py'})
            buffer.seek(0)
            original = Image.open(buffer).convert('RGB')
            assert hashlib.sha256(original.tobytes()).hexdigest() == manifest['frames'][generation]['pixel_sha256']
            animation.seek(generation)
            assert animation.info['duration'] == manifest['gif_frame_durations_ms'][generation]
            decoded = animation.convert('RGB')
            difference = ImageStat.Stat(ImageChops.difference(original, decoded))
            mean_error = sum(difference.mean) / 3
            # Palette quantization changes antialias colors slightly; original
            # full-color frames are bound exactly by their pixel hashes above.
            assert mean_error < 1.0, (generation, mean_error)
            errors.append(mean_error)
            if generation in (0, 5, 10):
                preview = CACHE / f'gif-generation-{generation}-width-800.png'
                decoded.resize((800, round(750 * 800 / 1080)), Image.Resampling.LANCZOS).save(preview)
                inspected.append(str(preview.relative_to(ROOT)))
            render.plt.close(fig)
    with Image.open(OUT / 'throughput.png') as image:
        image.resize((800, round(750 * 800 / 1080)), Image.Resampling.LANCZOS).save(CACHE / 'static-width-800.png')
    document = ROOT / 'docs/README.md'
    local_links = re.findall(r'\]\(([^)]+)\)', document.read_text())
    assert all((document.parent / link).exists() for link in local_links)
    result = {'status': 'passed', 'source_sha256': manifest['source_sha256'],
              'manifest_sha256': sha(OUT / 'throughput-data.json'),
              'generator_sha256': sha(ROOT / 'review/presentation/render_throughput.py'),
              'checker_sha256': sha(__file__), 'source_rows': len(source), 'frames': 11,
              'plotted_values_checked': sum(4 * (g + 1) for g in generations),
              'gif_mean_absolute_RGB_quantization_error_by_frame': errors,
              'saved_readme_size_previews': inspected + [str((CACHE / 'static-width-800.png').relative_to(ROOT))],
              'docs_index_local_links_checked': len(local_links),
              'source_unchanged': sha(ROOT / 'bench/results.csv') == manifest['source_sha256'],
              'scope': 'Source/data/artist/frame checks only; no benchmark or decoder execution.'}
    (ROOT / 'review/presentation/verification.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
