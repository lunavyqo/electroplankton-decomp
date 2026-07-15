// addr 0x02056d38 size 0x88
// Soft-float double >= (NaN → false).
//
// NONMATCHING: (div=58) multi-entry / shared-body runtime; pure C of ordered compare.

int func_02056d38(unsigned alo, unsigned ahi, unsigned blo, unsigned bhi) {
    unsigned ae = (ahi >> 20) & 0x7ffu;
    unsigned be = (bhi >> 20) & 0x7ffu;
    if ((ae == 0x7ffu && ((ahi << 12) | alo) != 0) ||
        (be == 0x7ffu && ((bhi << 12) | blo) != 0)) {
        return 0;
    }
    /* signed magnitude compare of (hi,lo) pairs */
    {
        int neg_a = (int)ahi < 0;
        int neg_b = (int)bhi < 0;
        unsigned ahm = ahi & ~0x80000000u;
        unsigned bhm = bhi & ~0x80000000u;
        int cmp;
        if (neg_a != neg_b) {
            cmp = neg_a ? -1 : 1;
        } else if (ahm != bhm) {
            cmp = (ahm < bhm) ? -1 : 1;
            if (neg_a) cmp = -cmp;
        } else if (alo != blo) {
            cmp = (alo < blo) ? -1 : 1;
            if (neg_a) cmp = -cmp;
        } else {
            cmp = 0;
        }
        return cmp >= 0;
    }
}
