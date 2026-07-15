// addr 0x020556d4 size 0x318
// _d_add — double add (MW soft-float runtime implementation).
//
// NONMATCHING: (div=198) C `a+b` only emits a bl stub into this symbol. Body is
// hand-structured runtime (was invalidly banked as asm paste).

double func_020556d4(double a, double b) {
    return a + b;
}
