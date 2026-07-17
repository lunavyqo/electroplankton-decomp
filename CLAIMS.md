# Claims

Coordinate so two people do not work the same address range.

Add a row when you start; remove or mark done when the range is matched or you
drop the claim.

| Module | Range (inclusive) | Claimant | Date (UTC) | Status | Notes |
|--------|-------------------|----------|------------|--------|-------|
| arm9   | 0x02050894–0x02050d2f | lunavyqo | 2026-07-16 | active | batch8: 7/8 MATCH (list helpers + power flag); near: 50a48 div62 regalloc (1.2/sp2p3) |
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
| arm9   | 0x02054e50–0x02055aef | grok | 2026-07-13 | active | math pure C MATCH + softfloat _d_add/_d_dtof retracted to NONMATCHING C drafts |
| arm9   | 0x020565ec–0x0205680b | grok | 2026-07-13 | active | soft-float float-cmp family — pure C near-miss (codegen wall) |
| arm9   | 0x0205680c–0x020572bb | lunavyqo | 2026-07-15 | active | soft-float cmp/_f_div: asm paste retracted → pure C NONMATCHING drafts |
| arm9   | 0x02055c10–0x020578ff | lunavyqo | 2026-07-15 | active | batch16 soft-float pure C: 1/16 MATCH (5655c qNaN); 15 NONMATCHING drafts — runtime is hand-seq / bl-target, not C float ops |
| arm9   | 0x02057900–0x02058447 | lunavyqo | 2026-07-13 | active | div runtime asm paste retracted (NONMATCHING C); 583fc/58400/58408 remain pure C MATCH |
| arm9   | 0x02006154–0x0200740f | lunavyqo | 2026-07-15 | active | pure C: 4/8 MATCH (6154,625c,6534,66f4); near: 65d4 div3, 6860 div4, 6a10/6d90 drafts |
| arm9   | 0x02052c44–0x02054e27 | lunavyqo | 2026-07-15 | done | batch8: scalbn/rem_pio2/k_rem_pio2/k_cos/k_sin/atan+init 52c44/52e10 MATCH 1.2/sp2p3 |
| arm9   | 0x020397e4–0x0203a667 | lunavyqo | 2026-07-15 | active | batch16: 11/16 MATCH + 4 NONMATCHING near-misses (1.2/sp2p3) |
| arm9   | 0x020514e0–0x02051f2b | lunavyqo | 2026-07-15 | active | batch16: 14/16 MATCH; near: cf4 div8, 514e0 draft (1.2/sp2p3) |
| arm9   | 0x0205274c–0x02052c43 | lunavyqo | 2026-07-15 | done | batch16: 15/16 MATCH; near: 52908 div2 regalloc (1.2/sp2p3) |
| arm9   | 0x02054e28–0x02054e4f | lunavyqo | 2026-07-15 | done | batch16: copysign double 54e28 MATCH 1.2/sp2p3 |
| arm9   | 0x02051f8c–0x020526ff + softfloat 0x02055af0–0x02055c0f | lunavyqo | 2026-07-15 | active | batch16 cart-pm: 6/16 MATCH (51f8c,52010,52138,52510,52568,526fc); near: 52908 div2, 52438/526a0 div6; softfloat clz wall |
| arm9   | 0x02002950–0x020033ef | lunavyqo | 2026-07-16 | active | batch16: 13/16 MATCH; near: 2d70/2f8c/320c (1.2/sp2p3) |
| arm9   | 0x02005888–0x02006153 | lunavyqo | 2026-07-17 | active | batch16: 15/16 MATCH; near: 5c20 FX interleave draft (1.2/sp2p3) |

| arm9   | 0x02004068–0x0200493b | grok | 2026-07-17 | active | batch16: 13/16 MATCH; near: 44b0/4590/469c loop-addr (1.2/sp2p3) |

## How to claim

1. Pull latest `main`.
2. Append a row with your handle, the module (`arm9`, `arm7`, overlay id, …),
   and the address range you will work.
3. Prefer a small commit that only updates this file.
4. Work only inside your claimed range until you release it.
| arm9   | 0x020036ec–0x02004067 | lunavyqo | 2026-07-17 | active | batch16: 13/16 MATCH; near: 36ec/387c/3d68 regalloc+pool (1.2/sp2p3) |
