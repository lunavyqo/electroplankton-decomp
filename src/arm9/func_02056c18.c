// addr 0x02056c18 size 0x94
// Soft-float double ordered-compare helper (APSR / special unord side effects).
//
// NONMATCHING: (div=42) cannot express APSR-only ABI in pure C; semantics draft only.

int func_02056c18(unsigned alo, unsigned ahi, unsigned blo, unsigned bhi) {
    unsigned ae = (ahi >> 20) & 0x7ffu;
    unsigned be = (bhi >> 20) & 0x7ffu;
    if ((ae == 0x7ffu && ((ahi << 12) | alo) != 0) ||
        (be == 0x7ffu && ((bhi << 12) | blo) != 0)) {
        return 1; /* unordered marker */
    }
    if (ahi == bhi && alo == blo) {
        return 0;
    }
    return (ahi != bhi) ? ((int)ahi < (int)bhi) : (alo < blo);
}
