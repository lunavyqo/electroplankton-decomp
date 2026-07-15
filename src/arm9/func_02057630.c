// addr 0x02057630 size 0x278
// _f_sub — single-precision sub (MW soft-float runtime implementation).
//
// NONMATCHING: C `a-b` is a bl stub into this runtime. Shared structure with (div=158)
// _f_add (cross-branch between add/sub specials). Needs focused pure-C or
// accepted impossibility — not a disasm dump.

float func_02057630(float a, float b) {
    return a - b;
}
