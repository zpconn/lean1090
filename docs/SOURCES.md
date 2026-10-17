# Sources and provenance

This is the checkpoint-1 source register. `GOAL.md` remains verbatim. The user's later chat decisions authorize additional readable ICAO tables and explicitly labeled `rs1090-derived` fallbacks; they also select the pinned oracle's ADS-B version behavior when sources differ.

| Source | Edition / revision actually read | Acquisition | SHA-256 / commit |
| --- | --- | --- | --- |
| ICAO Annex 10, Volume IV | Fourth edition, July 2007; consulted copy includes amendment 85 pages dated 18 November 2010 | [Vietnam Aviation Academy library PDF](https://library.vaa.edu.vn/uploads/books/files/1779161389741-c4db82415efd6dfa.pdf), downloaded with `curl`, extracted with pypdf (288 pages) | `0ddf4c14855ecb73009d912a5ef52bb2e559910548c574e88eacb72028b837ce` |
| ICAO Annex 10, Volume III, Part I, CPR excerpt | Amendment 77, 28 November 2002; §2.6, printed pages 5-88–5-94 | [University of Ljubljana CPR encoding PDF](https://lso.fe.uni-lj.si/literatura/Razno/Avionika/modes/CPRencoding.pdf), downloaded and read as a seven-page excerpt | `b1951e8215bb7d0a5ed8e419b056679b30c2709493446ca76c2065d5c67e2abe` |
| Junzi Sun, The 1090 Megahertz Riddle | Second edition, 2021 | [Author's PDF](https://mode-s.org/1090mhz/book-the_1090mhz_riddle-junzi_sun.pdf), downloaded with `curl`, extracted with pypdf (160 pages); [HTML chapters](https://mode-s.org/1090mhz/) | `29868db6d85ee15e9e54c22f5b9b7b8843c5069d9a7ed5ac6aff332ae998ffe0` |
| rs1090 | Commit of 2026-10-13, default features | [Repository](https://github.com/xoolive/rs1090/tree/685dfaa34c5ab186c691bca3cfe2a22e12517d30); cloned to `vendor/rs1090`, detached at pin | `685dfaa34c5ab186c691bca3cfe2a22e12517d30` |
| lean-zip | Current checkout and preserved development tag | [Repository](https://github.com/kim-em/lean-zip); cloned to `vendor/lean-zip` | HEAD `2f7a63f38195bc667a926881b55d10c9f8a88eeb`; `pre-split` `9bc0e7d28691223e669474ffdf4ed1041d2522b5` |
| Rust standard-library floating-point documentation | Online documentation consulted for IEEE binary64 format, significand size and arithmetic rounding; not an avionics standard | [`f64`](https://doc.rust-lang.org/std/primitive.f64.html) and [`f32` floating-point arithmetic](https://doc.rust-lang.org/std/primitive.f32.html#floating-point-arithmetic), supporting `Spec/Binary64.lean` | Live documentation; no immutable edition or downloaded-file hash claimed |

The ICAO-hosted `applications.icao.int/.../Annex10_Volume%204_cons.pdf` URL returned an HTML maintenance page. It was not used as a document source. The current ICAO catalogue lists a later sixth edition; this draft does **not** claim to have read that edition. References in `Spec/` identify the consulted edition, not the catalogue's current edition. A citation embedded in rs1090 is not evidence that its cited ICAO table was read. Such definitions use an `rs1090-derived` label unless independently sourced.

The local downloaded PDFs and extracted text are research caches under `.cache/sources/`, excluded from git. No standard is republished here. Technical encodings, equations and bit assignments are independently expressed in Lean; prose is not copied wholesale.

## lean-zip study completed before design

Commands run included `git rev-parse HEAD pre-split`, `git ls-tree pre-split`, `git show pre-split:PLAN.md`, `git show pre-split:PROGRESS.md`, `git show pre-split:progress/wide-refill-2854.md`, and reads of `Zip/Spec/Crc32.lean`, `Zip/Native/Crc32.lean`, and `conformance/Conformance/NativeDeflate.lean`.

The adopted lessons are a separate mathematical reference and runtime implementation, substantive semantic properties in addition to refinement, an independently constructed encoder, and an external conformance oracle. The preserved plans distinguish proof obligations from performance evidence. The wide-refill progress entry records both a successful experiment and a rejected faster one whose state relation would need a different proof. This project makes no claim that DEFLATE's measured gains predict Mode S performance.

## Pin verification

The official release endpoints `https://api.github.com/repos/leanprover/lean4/releases/latest` and `https://api.github.com/repos/leanprover-community/mathlib4/releases/latest` reported `v4.35.0`, published 2026-10-12 and 2026-10-13 respectively. `git ls-remote` resolved the Mathlib tag to `56a005855ea17e0b0958f73ec801ae140b0a1679`. `lean --version` reported Lean 4.35.0, compiler commit `eb6cafb7290e8bd5f2937522d8d804f58f02bafc`. `lake-manifest.json` pins Mathlib and its transitive dependencies.
