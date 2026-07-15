// addr 0x02055c10 size 0x364
// _d_mul — double-precision multiply (MW soft-float runtime implementation).
//
// NONMATCHING: C `a*b` for double only bl's here (~12B). Body is umull-based (div=217)
// 64-bit mantissa mul with IEEE specials — not recoverable as matching C
// from this pin without a true algorithm-level rewrite effort.

double func_02055c10(double a, double b) {
    return a * b;
}
