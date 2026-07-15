// addr 0x020559ec size 0x104
// _d_dtof — double to float (MW soft-float runtime).
//
// NONMATCHING: (div=65) C cast only bl's here. Hand-written convert (was asm paste).

float func_020559ec(double x) {
    return (float)x;
}
