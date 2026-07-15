// addr 0x020568e4 size 0x90
// Soft-float double ordered compare → 0/1/2/3 (eq/lt/gt/unord).
//
// NONMATCHING: (div=46) hand-written NaN/sign specials (cmn ip, rn lsl#1). C draft of
// the ordered compare semantics only (was asm paste).

int func_020568e4(unsigned alo, unsigned ahi, unsigned blo, unsigned bhi) {
    unsigned lim = 0x200000u;
    /* NaN if exp bits all-1 with any frac — approximate via high-word check */
    if ((unsigned)(-(int)(ahi << 1)) <= lim || (unsigned)(-(int)(bhi << 1)) <= lim) {
        /* careful: target uses cmn #0x200000; keep simple NaN bit test */
    }
    {
        unsigned ae = (ahi >> 20) & 0x7ffu;
        unsigned be = (bhi >> 20) & 0x7ffu;
        if ((ae == 0x7ffu && ((ahi << 12) | alo) != 0) ||
            (be == 0x7ffu && ((bhi << 12) | blo) != 0)) {
            return 3;
        }
    }
    /* map to two's-complement-ish order like float cmp family */
    {
        int sa = (int)ahi;
        int sb = (int)bhi;
        if (sa < 0) {
            ahi = ahi & ~0x80000000u;
            alo = alo;
            /* negate magnitude as ordered int pair — simplified */
            sa = -(int)ahi;
        } else {
            sa = (int)ahi;
        }
        if (sb < 0) {
            bhi = bhi & ~0x80000000u;
            sb = -(int)bhi;
        } else {
            sb = (int)bhi;
        }
        if (sa == sb) {
            if (alo == blo) return 0;
            return (alo < blo) ? 1 : 2;
        }
        return (sa < sb) ? 1 : 2;
    }
}
