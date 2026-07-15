// addr 0x02056664 size 0x38
// Soft-float float equality probe used as flag/r2 side-effect helper.
// NaN → sets r2=1 and returns; both ±0 → equal (Z); else cmp a,b leaves flags.
//
// NONMATCHING: APSR/r2 ABI cannot be expressed in pure C return values; (div=16)
// lim peep also differs (cmp lim, rn lsl#1 vs lsl+cmp). Logic draft only.

int func_02056664(unsigned a, unsigned b) {
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
    return (a != b);
}
