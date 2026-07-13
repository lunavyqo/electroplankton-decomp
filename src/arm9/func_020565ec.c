// addr 0x020565ec size 0x3c
// Soft-float !=  (NaN → true; both ±0 → false; else bit inequality).
//
// NEAR MISS under mwccarm 1.2/sp2p3 -O4,p:
//   target: mov lim; cmp lim, rn, lsl #1; movlo/bxlo  (60 bytes)
//   this C: lsl; cmp #imm; movhi/bxhi                 (64 bytes)
// Same logic; instruction selection peep rewrites the shared lim form.
// Not matched — do not bank as MATCH until verify passes.

int func_020565ec(unsigned a, unsigned b) {
    unsigned lim = 0xFF000000u;
    if (lim < (a << 1)) {
        return 1;
    }
    if (lim < (b << 1)) {
        return 1;
    }
    if (((a | b) << 1) == 0) {
        return 0;
    }
    return a != b;
}
