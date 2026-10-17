# Synthetic CPR oracle adapter

This unfrozen test harness calls the public CPR functions from the pinned
rs1090 checkout. It is separate from the frozen rs1090 benchmark harness and
does no timing. `scripts/check_cpr_differential.py` verifies the pin, builds
with default features and dist settings, and supplies the code/reference bits
produced by the frozen Lean reference adapter. See `docs/CPR-SYNTHETIC.md` for
coverage, comparison rules and complete reproduction commands.

The input is the CSV emitted by `scripts/FuzzCPR.lean`. `kind=0` selects a local
call; `surface` selects airborne or surface, and `odd` selects its parity.
`kind=1` selects a valid even/odd airborne pair; `kind=2` deliberately supplies
two even frames and checks rejection. `latest=1` selects the second member as
the latest call argument; otherwise the even member is latest. Coordinates
are bounded 17-bit words and references are finite IEEE-754 binary64 bit
patterns. The output carries the input ID and either rejection or exact
output coordinate bits. No acceptance or latitude/longitude calculation is
reimplemented here.
