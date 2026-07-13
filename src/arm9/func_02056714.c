// addr 0x02056714 size 0x44
// Soft-float ordered compare that leaves APSR flags set.
// Unordered (NaN): r2 = 0xff000000 + 0x10000000 with flags from adds.
// Both ±0: set Z. Else cmp with sign-aware operand swap.
//
// NEAR MISS — flag-returning helper; pure C does not leave cmp flags as
// the sole result under this pin (needs call/return bool shape instead).
// Not matched — do not bank as MATCH until verify passes.
//
// Semantic sketch only (does not match bytes):
//   if either NaN: set unordered flags; return
//   if both ±0: equal; return
//   if either negative: cmp(b, a); else cmp(a, b)

void func_02056714(unsigned a, unsigned b) {
    unsigned lim = 0xFF000000u;
    unsigned t;

    if (lim < (a << 1) || lim < (b << 1)) {
        t = 0xFF000000u;
        t += 0x10000000u;
        (void)t;
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
