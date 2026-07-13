// addr 0x02056758 size 0x3c
// Soft-float >  (NaN → false; map float bits to ordered ints, then >).
//
// NEAR MISS — same codegen gap as func_0205669c (cmphs/bicmi).
// Not matched — do not bank as MATCH until verify passes.

int func_02056758(int a, int b) {
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
    return a > b;
}
