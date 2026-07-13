// addr 0x0205669c size 0x3c
// Soft-float <  (NaN → false; map float bits to ordered ints, then <).
//
// NEAR MISS under mwccarm 1.2/sp2p3 -O4,p:
//   target uses cmphs + bicmi/rsbmi (60 bytes)
//   this C uses split NaN checks + biclt/rsblt (72 bytes)
// MWCC was not observed to emit cmphs or bicmi from pure C in this pin.
// Not matched — do not bank as MATCH until verify passes.

int func_0205669c(int a, int b) {
    unsigned lim = 0xFF000000u;
    if (lim < ((unsigned)a << 1)) {
        return 0;
    }
    if (lim < ((unsigned)b << 1)) {
        return 0;
    }
    if (a < 0) {
        a &= ~0x80000000;
        a = -a;
    }
    if (b < 0) {
        b &= ~0x80000000;
        b = -b;
    }
    return a < b;
}
