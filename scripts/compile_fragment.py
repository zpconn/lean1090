"""Compile exact frozen declarations under temporary integration imports.

The manifest contains the required exact proof types, without importing the
implementation back into the frozen reference module graph. This adapter does
not rewrite or filter any declaration. It prepends only the supplied imports.
"""
from pathlib import Path
import subprocess
import tempfile


def compile_fragment(path: Path, imports: list[str]) -> subprocess.CompletedProcess:
    body = path.read_bytes()
    prefix = ''.join(f'import {name}\n' for name in imports).encode() + b'\n'
    with tempfile.TemporaryDirectory(prefix='lean1090-proof-manifest-') as directory:
        wrapper = Path(directory) / 'Integration.lean'
        wrapper.write_bytes(prefix + body)
        return subprocess.run(['lake', 'env', 'lean', str(wrapper)],
                              text=True, capture_output=True)
