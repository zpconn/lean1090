# Commit attribution correction

On 2026-10-19, the repository owner requested that every pushed commit be
attributed to their GitHub account, `zpconn`. All 15 original commits were
rewritten with author and committer `zpconn <zpconn@gmail.com>`, using the
public account email returned by GitHub. Repository-local Git configuration now
uses that identity for future commits.

Every original commit's tree, message, author timestamp and committer timestamp
is unchanged. Parent links map to the corresponding rewritten parent. No source,
frozen file, test result, benchmark sample or historical report was edited by
the rewrite. The original history has a local rollback reference, which is not
pushed. Updating `main` uses an explicit lease against the previously published
tip, preventing replacement of someone else's intervening push.

## Historical evidence

Benchmark records retain the commit IDs that were actually measured. The
[complete mapping and exact commit records](../tests/evidence/publication/attribution-rewrite/history.json)
relate those original IDs to the current history. Each pair has the identical
Git tree ID. In particular, generation 10's original `d51a304` is now `0131adf`.
The metadata correction does not claim a new benchmark run.

| Original commit | Current commit with the same files |
| --- | --- |
| `2c70b69a032566cb729a073c4fce880cfc9f056b` | `7bfbdc5f74e3971824fc64e91445e8cc2b77fa72` |
| `dee72954b7ad8e4c525b2ffb391477f8f5439809` | `1dd99c29d36838b4b81c295322ed272a81f90a47` |
| `ff450a1faafe5d45076ce1ccc7cb1bef69cea12b` | `b41cf344fcb0e1673926b1dfe1166459a8e12089` |
| `1cec196fd30565c70573fb28b7d555c4c4b71d32` | `217d19621040cd96cf1d18105d945ad8c02ea578` |
| `f05d8b1bd697269efdb2d73b045fdf50a481f969` | `adc64e8bd09e645b5ed192a7f941bd34d5be4c40` |
| `3ba567f1d5039eb16ab033dd436d3d4f0f33c98b` | `9d3035871153e49ba0569dae917230776c649bf1` |
| `275329a2efd269dc44e549e4b6538d36277aaa3f` | `16ea34bde5bf9fa7498d64f12ded6206c8ce9704` |
| `eeb58261e6be0c2b87385f3064a88aed00d4d19a` | `0f272844932aac7ff388ce4326f9215f947094a7` |
| `cd4df90b6821ed8d375cb26e0e5baed6f6e9fecf` | `5462c467da8dbd9e53759edc3b483ce112798a52` |
| `7c3b44d246149a1c5aa671d119b6ba2be27d856b` | `52dac5615dc23d7d067aca1ef4fafbce1e05b3f5` |
| `78286f12feb79f8d8e3cdf2411ebd274161d1c3d` | `c9f00d6ce7679f6fadd0aa926610c5a6edde3dc1` |
| `0fb54f0661c4cd589816277b1a8996a9969bdc44` | `dac68b617dc16e507cd261687722eeb729da57b5` |
| `d51a3040984beb6f0f96b0f4fcf225ba2622a7e0` | `0131adfd5fe6f2ba4b18af1b7f8dccdb474354a5` |
| `f9a53b642f01c2d1396275955eba5b2a5af597e2` | `b7a738f63b73a01ae55e36edf2852487dbb74a6f` |
| `36a178f4afe5b451ce5d52824ee0fdf597685aa4` | `bf77541ea3cf635eec615df8b33bfab3fe602cb6` |

Some historical review scripts use `git show` with an original commit ID. In a
fresh clone, the following optional command restores the exact original commit
objects locally from the recorded metadata and the unchanged published trees.
It verifies each object ID and creates no branch, tag, replacement or remote ref.
It does not change `main` or its attribution. Historical scripts that also
require their original HEAD, build outputs or local paths still need the
recorded checkout and execution context.

```sh
python3 - <<'PYTHON'
import hashlib, json, subprocess
from pathlib import Path
record = json.loads(Path('tests/evidence/publication/attribution-rewrite/history.json').read_text())
validated = []
for entry in record['commits']:
    raw = entry['raw_commit'].encode()
    header = b'commit ' + str(len(raw)).encode() + b'\0'
    assert hashlib.sha1(header + raw).hexdigest() == entry['old']
    tree = subprocess.check_output(['git', 'rev-parse', entry['new'] + '^{tree}'], text=True).strip()
    assert tree == entry['tree']
    assert raw.split(b'\n', 1)[0] == b'tree ' + tree.encode()
    validated.append((entry['old'], raw))
for original, raw in validated:
    restored = subprocess.check_output(['git', 'hash-object', '-t', 'commit', '-w', '--stdin'], input=raw).decode().strip()
    assert restored == original
print('Restored 15 historical commit objects locally; refs unchanged.')
PYTHON
```
