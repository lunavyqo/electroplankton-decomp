// addr 0x02056e54 size 0x54
// Soft-float double isunordered (NaN → 1); multi-entry into shared body.
//
// NONMATCHING: (div=27) entry branches into sibling; pure C of NaN check only.

int func_02056e54(unsigned alo, unsigned ahi, unsigned blo, unsigned bhi) {
    unsigned ae = (ahi >> 20) & 0x7ffu;
    unsigned be = (bhi >> 20) & 0x7ffu;
    if (ae == 0x7ffu && ((ahi << 12) | alo) != 0) {
        return 1;
    }
    if (be == 0x7ffu && ((bhi << 12) | blo) != 0) {
        return 1;
    }
    return 0;
}
