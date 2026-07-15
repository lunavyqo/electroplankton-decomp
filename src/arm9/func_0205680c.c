// addr 0x0205680c size 0x24
// Soft-float float isunordered — either NaN → 1, else 0.
//
// NONMATCHING: (div=8) target uses cmp lim, rn, lsl #1 / movlo (same peep wall as 565ec).

int func_0205680c(unsigned a, unsigned b) {
    unsigned lim = 0xFF000000u;
    if (lim < (a << 1)) {
        return 1;
    }
    if (lim < (b << 1)) {
        return 1;
    }
    return 0;
}
