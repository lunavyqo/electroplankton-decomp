// addr 0x020569fc size 0x88
// Soft-float double == (NaN → false).
//
// NONMATCHING: (div=40) pure C semantics draft; target is hand-written runtime.

int func_020569fc(unsigned alo, unsigned ahi, unsigned blo, unsigned bhi) {
    unsigned ae = (ahi >> 20) & 0x7ffu;
    unsigned be = (bhi >> 20) & 0x7ffu;
    if ((ae == 0x7ffu && ((ahi << 12) | alo) != 0) ||
        (be == 0x7ffu && ((bhi << 12) | blo) != 0)) {
        return 0;
    }
    if (((alo | blo) == 0) && (((ahi | bhi) << 1) == 0)) {
        return 1;
    }
    return (alo == blo) && (ahi == bhi);
}
