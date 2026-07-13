// addr 0x020567d0 size 0x3c
// Soft-float ordered compare → APSR (quiet NaN: early return, no special r2).
//
// NEAR MISS — flag-returning helper; pure C under this pin does not match.
// Not matched — do not bank as MATCH until verify passes.
//
// Semantic sketch only (does not match bytes):
//   if either NaN: return (flags from last NaN check)
//   if both ±0: equal; return
//   if either negative: cmp(b, a); else cmp(a, b)

void func_020567d0(unsigned a, unsigned b) {
    unsigned lim = 0xFF000000u;

    if (lim < (a << 1) || lim < (b << 1)) {
        return;
    }
    if (((a | b) << 1) == 0) {
        return;
    }
    if ((int)(a | b) < 0) {
        (void)(b < a);
    } else {
        (void)(a < b);
    }
}
