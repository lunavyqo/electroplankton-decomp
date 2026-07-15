// addr 0x02056ea8 size 0x50
// Soft-float double isordered (NaN → 0).
//
// NONMATCHING: (div=27) pure C inverse of isunordered.

int func_02056ea8(unsigned alo, unsigned ahi, unsigned blo, unsigned bhi) {
    unsigned ae = (ahi >> 20) & 0x7ffu;
    unsigned be = (bhi >> 20) & 0x7ffu;
    if (ae == 0x7ffu && ((ahi << 12) | alo) != 0) {
        return 0;
    }
    if (be == 0x7ffu && ((bhi << 12) | blo) != 0) {
        return 0;
    }
    return 1;
}
