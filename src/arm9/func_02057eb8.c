// addr 0x02057eb8 size 0x544
// _d_div — double-precision division (MW soft-float runtime).
//
// NONMATCHING: (div=337) C `a/b` only bl's here. Large hand-written body
// (was invalidly banked as asm paste).

double func_02057eb8(double a, double b) {
    return a / b;
}
