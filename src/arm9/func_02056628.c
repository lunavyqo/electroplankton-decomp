// addr 0x02056628 size 0x3c
// Soft-float ==  (NaN → false; both ±0 → true; else bit equality).
//
// NEAR MISS under mwccarm 1.2/sp2p3 -O4,p (same lim peep as !=; 64 vs 60).
// Not matched — do not bank as MATCH until verify passes.

int func_02056628(unsigned a, unsigned b) {
    unsigned lim = 0xFF000000u;
    if (lim < (a << 1)) {
        return 0;
    }
    if (lim < (b << 1)) {
        return 0;
    }
    if (((a | b) << 1) == 0) {
        return 1;
    }
    return a == b;
}
