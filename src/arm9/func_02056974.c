// addr 0x02056974 size 0x88
// Soft-float double != (NaN → true).
//
// NONMATCHING: (div=41) pure C semantics draft; target is hand-written runtime.

int func_02056974(unsigned alo, unsigned ahi, unsigned blo, unsigned bhi) {
    unsigned ae = (ahi >> 20) & 0x7ffu;
    unsigned be = (bhi >> 20) & 0x7ffu;
    if ((ae == 0x7ffu && ((ahi << 12) | alo) != 0) ||
        (be == 0x7ffu && ((bhi << 12) | blo) != 0)) {
        return 1;
    }
    if (((alo | blo) == 0) && (((ahi | bhi) << 1) == 0)) {
        return 0; /* both ±0 */
    }
    return (alo != blo) || (ahi != bhi);
}
