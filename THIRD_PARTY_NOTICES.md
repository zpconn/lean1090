# Third-party notices

These notices identify upstream material used by lean1090. They do not assign
a license to lean1090's original code or replace the licenses of dependencies.

## rs1090

The pinned comparison implementation is rs1090 commit
`685dfaa34c5ab186c691bca3cfe2a22e12517d30`. Its test vectors, corpus and airport
test snapshots, and observed policies inform the regression suites and
explicitly labeled rs1090-derived definitions.
The upstream checkout is not included in Git. Source and vector provenance are
recorded in [SCOPE.md](SCOPE.md), [the unit-port inventory](docs/UPSTREAM-UNIT-PORT.md)
and [the source register](docs/SOURCES.md).

The following is the complete notice read from `license.md` at that commit
(SHA-256 `afbf9af29c73e18deaca318458be8ddff5a725b787b171e401e20bb4ddc52ef9`):

> MIT License
>
> Copyright (c) 2024 Xavier Olive
>
> Permission is hereby granted, free of charge, to any person obtaining a copy
> of this software and associated documentation files (the "Software"), to deal
> in the Software without restriction, including without limitation the rights
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
> copies of the Software, and to permit persons to whom the Software is
> furnished to do so, subject to the following conditions:
>
> The above copyright notice and this permission notice shall be included in all
> copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
> SOFTWARE.

## Rust libm 0.2.16

[Impl/Libm.lean](Impl/Libm.lean) translates `hypot.rs`, `atan.rs` and `atan2.rs`
from Rust libm 0.2.16 into Lean for the tested numerical presentation boundary.
It preserves operation order and coefficient bit patterns. This translation
does not provide a theorem about Lean's hardware Float operations and is not
the software-binary64 Comm-B inference model.

The complete upstream license and notices are retained byte-for-byte in
[docs/licenses/rust-libm-0.2.16.txt](docs/licenses/rust-libm-0.2.16.txt), SHA-256
`3823dda7cf046602f4b4e77ec8e227863dc4736037cc85bb33d9f19febe16bb7`.
That file identifies the MIT license for the library, contributor terms and
the origins of portions of the math code. The original `atan.rs` and
`atan2.rs` headers also contain these notices, preserved here:

> Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
>
> Developed at SunPro, a Sun Microsystems, Inc. business.
> Permission to use, copy, modify, and distribute this
> software is freely granted, provided that this notice
> is preserved.

For `atan2.rs`, the corresponding development attribution is:

> Developed at SunSoft, a Sun Microsystems, Inc. business.

Their recorded origins are FreeBSD `msun/src/s_atan.c` and `msun/src/e_atan2.c`.
See [numerical presentation compatibility](docs/NUMERICAL-PRESENTATION.md)
for the runtime scope and differential check.

## Tools, dependencies and research sources

Lean and Mathlib are pinned by `lean-toolchain`, `lakefile.toml` and
`lake-manifest.json`; Rust dependencies are pinned by the harness Cargo
lockfiles. Their source trees and binaries are restored separately, rather
than vendored in this repository. Their own license files remain authoritative.
The consulted Lean and Mathlib licenses are Apache-2.0.

The lean-zip repository was studied for its proof/implementation split,
conformance workflow and development logs. Its consulted license is Apache-2.0.
[docs/SOURCES.md](docs/SOURCES.md) records the exact commits and files read;
its checkout is excluded from this repository.

ICAO documents and Junzi Sun's *The 1090 Megahertz Riddle* are specification and
worked-example sources. [docs/SOURCES.md](docs/SOURCES.md) records the editions,
acquisition locations and document hashes, and specification docstrings cite
the relevant sections or tables. Downloaded PDFs and extracted document text
are research caches excluded from Git. These software notices do not grant
rights to those publications.
