// addr 0x02055f8c size 0x3b4
// _d_sub — double-precision sub (MW soft-float runtime implementation).
//
// NONMATCHING: C `a-b` is a bl stub. Shares special-case paths with _d_add (div=237)
// (0x020556d4). Requires focused work; asm paste is not a valid match.

double func_02055f8c(double a, double b) {
    return a - b;
}
