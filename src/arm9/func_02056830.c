// addr 0x02056830 size 0x24
// Soft-float float isordered — either NaN → 0, else 1.
//
// NONMATCHING: (div=8) inverse of isunordered; lim peep wall (was asm paste).

int func_02056830(unsigned a, unsigned b) {
    unsigned lim = 0xFF000000u;
    if (lim < (a << 1)) {
        return 0;
    }
    if (lim < (b << 1)) {
        return 0;
    }
    return 1;
}
