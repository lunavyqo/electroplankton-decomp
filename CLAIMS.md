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

| arm9   | 0x0201ac00–0x0201c6c0 | lunavyqo | 2026-07-17 | active | batch16: 6/16 MATCH (ac00,b51c,b54c,b684,b690,c228); near: c0f0/c2b0/bd58/bf24 (1.2/sp2p3) |

| arm9   | 0x02027fb4–0x0202904f | lunavyqo | 2026-07-18 | active | batch16: 12/16 MATCH (27fb4..28f68 cluster); near: 28560 div24, 283b4/28190/28698 drafts (1.2/sp2p3) |

| arm9   | 0x02001558–0x020019cb | lunavyqo | 2026-07-18 | done | batch16: 16/16 MATCH heap/async queue cluster 1558-19c0 (1.2/sp2p3) |

| arm9   | 0x0203e340–0x0203f1bc | lunavyqo | 2026-07-18 | active | batch16: 13/16 MATCH (e340–ed6c cluster); near: e9f8 div11, eba4 div20; f1bc deferred (1.2/sp2p3) |

| arm9   | 0x02000070–0x02000a5b | lunavyqo | 2026-07-18 | done | batch16: 16/16 MATCH BIOS SWI wrappers + AutoloadCallback (1.2/sp2p3; thumb #pragma + swi) |

| arm9   | VBlankIntrWait/WaitByLoop + 14 empty ARM stubs | lunavyqo | 2026-07-18 | done | batch16: 16/16 MATCH (svc #5/#3 thumb + bx-lr stubs 00b44…3b6bc; 1.2/sp2p3) |

| arm9   | Mod + stubs/setters/const leaves (mixed addrs) | lunavyqo | 2026-07-18 | done | batch16: 16/16 MATCH — Mod svc#9 thumb, 6 empty bx-lr, 3 const, 1 epilogue, 5 field setters (1.2/sp2p3) |
| arm9   | simple field accessors (mixed: 099e0…26e98) | lunavyqo | 2026-07-18 | done | batch16: 16/16 MATCH — 9 new getters/setters + 7 re-verified prior leaves (1.2/sp2p3) |
| arm9   | simple field accessors (mixed: 26ea0…2f814) | lunavyqo | 2026-07-18 | done | batch16: 16/16 MATCH — 8-byte getters/setters (offsets 0x4…0x9a8, one u16) (1.2/sp2p3) |

| arm9   | simple leaves (mixed: 315f8…4f700) | lunavyqo | 2026-07-18 | done | batch16: 16/16 MATCH — field getters/setters, const leaves, clz/mcr/swp wrappers (1.2/sp2p3) |

| arm9   | 0x02038140–0x02038157, 0x02039794–0x0203979f, 0x0203a73c–0x0203a747, 0x0203baf4–0x0203baff, 0x0203d3d0–0x0203d3db, 0x0203d43c–0x0203d447, 0x02042060–0x0204206b, 0x0204224c–0x02042257, 0x02042294–0x0204229f, 0x02042ca0–0x02042cab, 0x02043118–0x02043123, 0x0204407c–0x0204409f, 0x020493e0–0x020493eb | lunavyqo | 2026-07-18 | done | batch16: 15/16 MATCH simple accessors/trampolines-4; near: 493e0 div2 r1-vs-ip regperm (1.2/sp2p3) |

## How to claim

1. Pull latest `main`.
2. Append a row with your handle, the module (`arm9`, `arm7`, overlay id, …),
   and the address range you will work.
3. Prefer a small commit that only updates this file.
4. Work only inside your claimed range until you release it.
| arm9   | 0x020036ec–0x02004067 | lunavyqo | 2026-07-17 | active | batch16: 13/16 MATCH; near: 36ec/387c/3d68 regalloc+pool (1.2/sp2p3) |

| arm9   | 0x0200493c–0x0200539f | lunavyqo | 2026-07-18 | active | batch16: 10/16 MATCH; near: 4ba4/4f08/5024/51ec/5264/528c (1.2/sp2p3) |

| arm9   | 0x020019cc, 0x02009300–0x02009333, 0x0200a2f8, 0x0200a704–0x0200a7ff, 0x0200b02c–0x0200b083, 0x020513c4 | lunavyqo | 2026-07-18 | done | batch16 simple accessors/trampolines: 16/16 MATCH 1.2/sp2p3 |

| arm9   | 0x0200b168–0x0200b18f, 0x0200c860–0x0200c86b, 0x0201625c–0x02016267, 0x02017210–0x0201721b, 0x02019678–0x02019683, 0x0201df10–0x0201df1b, 0x0201ea34–0x0201ea3f, 0x02021c40–0x02021c4b, 0x02023bf0–0x02023bfb, 0x020256f0–0x020256fb, 0x02025c84–0x02025ca7, 0x02026ea8–0x02026eb3 | lunavyqo | 2026-07-18 | done | batch16 simple accessors/trampolines-2: 16/16 MATCH 1.2/sp2p3 |

| arm9   | 0x02026ebc, 0x02029b84, 0x02029f08, 0x0202b238, 0x0202b4fc, 0x0202b510, 0x0202b584, 0x0202b590, 0x0202c464, 0x0202e96c, 0x020303e8, 0x02030dac, 0x02033260, 0x0203389c, 0x02033918, 0x02036f18 | lunavyqo | 2026-07-18 | done | batch16 simple accessors/trampolines-3: 16/16 MATCH 1.2/sp2p3 |

| arm9   | 0x02002498, 0x02002560, 0x0200259c, 0x02002644, 0x02007600, 0x02009544–0x02009573, 0x020493e0, 0x0204af50, 0x0204b7b0–0x0204b7d3, 0x0204d710, 0x02051f74–0x02051f8b | lunavyqo | 2026-07-18 | done | batch16 simple accessors-4b: 16/16 MATCH (globals, struct fields, CP15 DSB/WFI, mrs mode, delay, r1/ip trampolines) 1.2/sp2p3 |
| arm9   | 0x020114c4, 0x02012f40, 0x020144f4, 0x0201a2cc, 0x0201a3d0, 0x0201df1c, 0x02021258, 0x02022d3c, 0x02026ec8, 0x0202b1fc, 0x0202b574, 0x0202e940, 0x0202f568, 0x020338a8, 0x02033c60, 0x0203598c | lunavyqo | 2026-07-18 | done | batch16 simple accessors-4: 16/16 MATCH (Vec3i ldm/stm, halfword pack, mla index, global table, arg-prep tail trampolines) 1.2/sp2p3 |
| arm9   | 0x02009574–0x020095bb, 0x02009700, 0x02009a74, 0x0200b038, 0x0200c75c, 0x0200c944, 0x020100f0, 0x02039344, 0x0203d898, 0x020419a8, 0x020430e0–0x020430ff, 0x02043124, 0x02043390 | lunavyqo | 2026-07-18 | done | batch16 simple accessors-4d: 16/16 MATCH (data_0208938c fields, globals, array tables, halfword exchange, conditional stores, tail trampolines) 1.2/sp2p3 |
