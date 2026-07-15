// addr 0x02056340 size 0x21c
// _f_add — single-precision add (MW soft-float runtime implementation).
//
// NONMATCHING: same as _f_mul — C `a+b` only bl's here. Hand-written runtime (div=135)
// (eors/sign, clz renorm, sticky round). Do not bank asm paste as a match.

float func_02056340(float a, float b) {
    return a + b;
}
