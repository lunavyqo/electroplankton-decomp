# Claims

Coordinate so two people do not work the same address range.

Add a row when you start; remove or mark done when the range is matched or you
drop the claim.

| Module | Range (inclusive) | Claimant | Date (UTC) | Status | Notes |
|--------|-------------------|----------|------------|--------|-------|
| arm9   | 0x02000eb4–0x02001133 | grok | 2026-07-12 | done | heap/file cluster 0eb4-10d8 MATCH 1.2/sp2p3 |
| arm9   | 0x02001a64–0x02001b43 | grok | 2026-07-13 | done | tail-call wrappers 1a64-1b28 MATCH 1.2/sp2p3 |
| arm9   | 0x02001134–0x02001557 | grok | 2026-07-12 | done | pad/touch cluster 1134-14f4 MATCH 1.2/sp2p3 |
| arm9   | 0x02001b44–0x02001b6b | grok | 2026-07-12 | done | func_02001b44 MATCH 1.2/sp2p3 |
| arm9   | 0x020078a4–0x02007923 | grok | 2026-07-12 | done | func_020078a4 MATCH 1.2/sp2p3 |
| arm9   | 0x020092ac–0x020092ff | grok | 2026-07-12 | done | func_020092ac MATCH 1.2/sp2p3 |
| arm9   | 0x0200c7ac–0x0200c7eb | grok | 2026-07-12 | done | func_0200c7ac MATCH 1.2/sp2p3 |
| arm9   | 0x0201005c–0x020100ef | grok | 2026-07-12 | done | func_0201005c MATCH 1.2/sp2p3 |
| arm9   | 0x02014bf0–0x02014ceb | grok | 2026-07-12 | done | func_02014bf0 MATCH 1.2/sp2p3 |
| arm9   | 0x0201c468–0x0201c6bf | grok | 2026-07-12 | done | func_0201c468 MATCH 1.2/sp2p3 |
| arm9   | 0x02023bfc–0x02023c63 | grok | 2026-07-12 | done | func_02023bfc MATCH 1.2/sp2p3 |
| arm9   | 0x02054e50–0x02055aef | grok | 2026-07-13 | done | math+softfloat: cos/fabs/floor/frexp/ldexp/sin/_d_add/_d_dtof MATCH 1.2/sp2p3 |
| arm9   | 0x020565ec–0x0205680b | grok | 2026-07-13 | active | soft-float cmp family — pure C near-miss (codegen wall) |

## How to claim

1. Pull latest `main`.
2. Append a row with your handle, the module (`arm9`, `arm7`, overlay id, …),
   and the address range you will work.
3. Prefer a small commit that only updates this file.
4. Work only inside your claimed range until you release it.
