#!/usr/bin/env python3
"""Render repository charts using only the recorded benchmark CSV as data.

Run with the project's existing plotting environment; no decoder or benchmark
is executed. The GIF has one distinct frame per recorded generation.
"""
import argparse
import sys
sys.dont_write_bytecode = True
import csv
from decimal import Decimal
import hashlib
import io
import json
import os
from pathlib import Path
import re

os.environ.setdefault('MPLCONFIGDIR', str(Path('.cache/matplotlib-presentation').resolve()))
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter, MultipleLocator
from PIL import Image

BLUE = '#185FA5'
INK = '#233042'
GREY = '#68727D'
GOLD = '#AD7015'
GRID = '#E4E8EC'
TARGET = Decimal('2.00')
MODES = ('decode', 'cpr')


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def load_rows(path):
    with path.open(newline='') as stream:
        reader = csv.DictReader(stream)
        assert reader.fieldnames == ['commit', 'generation', 'lean1090_msg_s',
                                     'rs1090_msg_s', 'note', 'mode', 'lean_over_rs1090']
        rows = list(reader)
    values = {}
    for row in rows:
        generation = int(row['generation'])
        assert generation >= 0 and str(generation) == row['generation']
        assert re.fullmatch(r'[0-9a-f]{40}', row['commit'])
        assert row['mode'] in MODES and (generation, row['mode']) not in values
        lean = Decimal(row['lean1090_msg_s'])
        rust = Decimal(row['rs1090_msg_s'])
        reported = Decimal(row['lean_over_rs1090'])
        assert lean.is_finite() and rust.is_finite() and reported.is_finite()
        assert lean > 0 and rust > 0 and reported > 0
        ratio = lean / rust
        # CSV ratios and rates were serialized from binary64 arithmetic.
        assert abs(ratio - reported) < Decimal('1e-14'), (generation, row['mode'])
        values[generation, row['mode']] = {**row, 'ratio_recomputed': str(ratio)}
    generations = sorted({generation for generation, _ in values})
    assert generations == list(range(max(generations) + 1))
    assert len(rows) == 2 * len(generations)
    for generation in generations:
        assert all((generation, mode) in values for mode in MODES)
        assert values[generation, 'decode']['commit'] == values[generation, 'cpr']['commit']
    return generations, values


def draw(generations, rows, last):
    plt.rcParams.update({
        'font.family': 'DejaVu Sans', 'font.size': 10.5,
        'text.color': INK, 'axes.labelcolor': INK, 'xtick.color': GREY,
        'ytick.color': GREY, 'svg.hashsalt': 'lean1090-throughput-v1',
        'axes.edgecolor': '#B5BEC7', 'axes.linewidth': 0.7,
    })
    fig = plt.figure(figsize=(9, 6.25), dpi=120, facecolor='white')
    top = fig.add_axes([0.10, 0.48, 0.85, 0.33])
    bottom = fig.add_axes([0.10, 0.16, 0.85, 0.23])
    shown = generations[:last + 1]
    decode = [float(rows[g, 'decode']['lean1090_msg_s']) / 1000 for g in shown]
    rust = [float(rows[g, 'decode']['rs1090_msg_s']) / 1000 for g in shown]
    ratio = [float(rows[g, 'decode']['ratio_recomputed']) for g in shown]
    cpr = [float(rows[g, 'cpr']['ratio_recomputed']) for g in shown]
    generation = shown[-1]
    fig.text(0.065, 0.95, 'lean1090 throughput', fontsize=21, weight='bold')
    fig.text(0.065, 0.909, 'Single core · measured generations · decode and decode + CPR',
             fontsize=11, color=GREY)
    fig.text(0.95, 0.95, f'GENERATION {generation}', ha='right', fontsize=10.5, weight='bold', color=GREY)
    fig.text(0.95, 0.853, f'Decode  {ratio[-1]:.2f}×    ·    Decode + CPR  {cpr[-1]:.2f}×',
             ha='right', fontsize=12, weight='bold')
    top.set_title('Decode throughput · thousand messages / second', loc='left', fontsize=10.5, pad=11)
    lean_line, = top.plot(shown, decode, color=BLUE, lw=2.6, marker='o', ms=5.5,
                         label='lean1090', zorder=3)
    rust_line, = top.plot(shown, rust, color=GREY, lw=1.9, marker='s', ms=4.2,
                         markerfacecolor='white', label='rs1090', zorder=2)
    top.legend(handles=[lean_line, rust_line], loc='upper left', frameon=False, ncol=2,
               borderaxespad=0.2, fontsize=10.5)
    maximum = max(float(rows[g, 'decode'][key]) / 1000
                  for g in generations for key in ('lean1090_msg_s', 'rs1090_msg_s'))
    top.set_ylim(0, max(275, (int(maximum / 50) + 1) * 50))
    top.yaxis.set_major_locator(MultipleLocator(50))
    top.tick_params(axis='x', labelbottom=False)
    top.annotate(f'{decode[-1]:.1f}k', (generation, decode[-1]), xytext=(0, 11),
                 textcoords='offset points', ha='center', color=BLUE, weight='bold', fontsize=10)
    top.annotate(f'{rust[-1]:.1f}k', (generation, rust[-1]), xytext=(0, -17),
                 textcoords='offset points', ha='center', color=GREY, fontsize=10)
    bottom.set_title("Lean throughput / that generation's rs1090 throughput", loc='left', fontsize=10.5, pad=10)
    bottom.axhline(float(TARGET), color=INK, lw=1.2, linestyle=(0, (5, 4)), zorder=1)
    bottom.text(0.16, float(TARGET) + 0.045, f'Target {TARGET:.2f}× · both modes', fontsize=10, color=INK)
    bottom.axhline(1.0, color='#B5BEC7', lw=0.7, zorder=0)
    bottom.plot(shown, ratio, color=BLUE, lw=2.6, marker='o', ms=5.5, label='Decode', zorder=3)
    bottom.plot(shown, cpr, color=GOLD, lw=1.8, linestyle=(0, (3, 2)), marker='^',
                ms=5, markerfacecolor='white', label='Decode + CPR', zorder=2)
    bottom.legend(loc='lower right', frameon=False, ncol=2, borderaxespad=0.3, fontsize=10)
    bottom.set_ylim(0, max(float(TARGET) * 1.15,
                          max(float(rows[g, m]['ratio_recomputed']) for g in generations for m in MODES) * 1.14))
    bottom.yaxis.set_major_locator(MultipleLocator(0.25))
    bottom.yaxis.set_major_formatter(FuncFormatter(lambda value, _: f'{value:g}×'))
    bottom.set_xlabel('Optimization generation', labelpad=9)
    for axis in (top, bottom):
        axis.set_xlim(-0.35, max(generations) + 0.45)
        axis.set_xticks(generations)
        axis.grid(axis='y', color=GRID, lw=0.7, zorder=0)
        axis.spines[['top', 'right']].set_visible(False)
        axis.tick_params(length=0, pad=7)
    fig.text(0.065, 0.045, 'Source: bench/results.csv  ·  Each generation uses its own rs1090 measurement.',
             fontsize=9, color=GREY)
    fig.text(0.065, 0.018, 'Points are recorded results; connecting lines guide the eye. No uncertainty intervals supplied in the CSV.',
             fontsize=8.5, color=GREY)
    return fig


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, default=Path('bench/results.csv'))
    parser.add_argument('--output-dir', type=Path, default=Path('docs/images'))
    parser.add_argument('--expected-generations', type=int, default=18)
    args = parser.parse_args()
    original = args.input.read_bytes()
    generations, rows = load_rows(args.input)
    assert len(generations) == args.expected_generations
    args.output_dir.mkdir(parents=True, exist_ok=True)
    frames = []
    frame_manifest = []
    for last, generation in enumerate(generations):
        fig = draw(generations, rows, last)
        buffer = io.BytesIO()
        fig.savefig(buffer, format='png', dpi=120, metadata={'Software': 'lean1090 render_throughput.py'})
        buffer.seek(0)
        frame = Image.open(buffer).convert('RGB')
        frames.append(frame)
        frame_manifest.append({'generation': generation, 'pixel_sha256': hashlib.sha256(frame.tobytes()).hexdigest(),
                               'plotted_generations': generations[:last + 1],
                               'decode_ratio_label': f"{float(rows[generation, 'decode']['ratio_recomputed']):.2f}×",
                               'cpr_ratio_label': f"{float(rows[generation, 'cpr']['ratio_recomputed']):.2f}×"})
        if generation == generations[-1]:
            (args.output_dir / 'throughput.png').write_bytes(buffer.getvalue())
            fig.savefig(args.output_dir / 'throughput.svg', format='svg', metadata={'Date': None, 'Creator': 'lean1090 render_throughput.py'})
        plt.close(fig)
    gif = args.output_dir / 'throughput.gif'
    durations = [900] + [700] * (len(frames) - 2) + [2800]
    frames[0].save(gif, save_all=True, append_images=frames[1:], duration=durations,
                   loop=0, disposal=2, optimize=False)
    with Image.open(gif) as saved:
        assert saved.n_frames == len(generations)
        assert saved.size == frames[-1].size == (1080, 750)
        saved_durations = []
        for i in range(saved.n_frames):
            saved.seek(i)
            saved_durations.append(saved.info['duration'])
        assert saved_durations == durations
    assert len({row['pixel_sha256'] for row in frame_manifest}) == len(generations)
    assert args.input.read_bytes() == original
    outputs = {name: {'sha256': sha(args.output_dir / name), 'bytes': (args.output_dir / name).stat().st_size}
               for name in ('throughput.png', 'throughput.svg', 'throughput.gif')}
    manifest = {
        'kind': 'source_bound_static_and_animated_benchmark_presentation',
        'source': str(args.input), 'source_sha256': hashlib.sha256(original).hexdigest(),
        'generator': str(Path(__file__).relative_to(Path.cwd())), 'generator_sha256': sha(__file__),
        'matplotlib_version': matplotlib.__version__, 'rows': [rows[g, m] for g in generations for m in MODES],
        'generations': generations, 'frame_count': len(frames), 'frames': frame_manifest,
        'gif_frame_durations_ms': durations, 'image_size': [1080, 750],
        'target_ratio': str(TARGET), 'outputs': outputs,
        'checks': ['Exactly one positive finite row per generation/mode and one commit per generation.',
                   'Every displayed ratio recomputed from the same row and reconciled with stored ratio.',
                   'Complete contiguous generation coverage and exactly one distinct GIF frame per generation.',
                   'Fixed axes across frames; future data points are not shown in earlier frames.',
                   'Source CSV bytes unchanged; no benchmark was executed.'],
    }
    (args.output_dir / 'throughput-data.json').write_text(json.dumps(manifest, indent=2, ensure_ascii=False) + '\n')
    print(json.dumps({'status': 'passed', 'rows': len(rows), 'frames': len(frames), 'outputs': outputs}, indent=2))


if __name__ == '__main__':
    main()
