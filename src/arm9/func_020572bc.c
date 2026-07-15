// addr 0x020572bc size 0x84
// _f_ftod — float bits → double bits (soft-float runtime).
//
// NONMATCHING: hand-written special-case tree (norm/denorm/inf/nan) with (div=49)
// pool constant 0x7ff00000. (double)float cast only emits a bl stub.

unsigned long long func_020572bc(unsigned f) {
    unsigned sign = f & 0x80000000u;
    unsigned exp = (f >> 23) & 0xffu;
    unsigned frac = f << 9;
    unsigned hi;
    unsigned lo;
    if (exp == 0u) {
        if (frac == 0u) {
            return ((unsigned long long)sign) << 32;
        }
        /* denorm normalize */
        frac >>= 1;
        {
            unsigned n = (unsigned)__cntlzw(frac);
            frac <<= n;
            exp = 1u - n;
        }
        frac += frac;
        exp += 0x380u;
        lo = frac << 20;
        hi = sign | (frac >> 12) | (exp << 20);
        return ((unsigned long long)hi << 32) | lo;
    }
    if (exp == 0xffu) {
        if (frac == 0u) {
            /* inf */
            return ((unsigned long long)(sign | 0x7ff00000u) << 32);
        }
        /* nan */
        return 0x7fffffffffffffffull;
    }
    exp += 0x380u;
    lo = frac << 20;
    hi = sign | (frac >> 12) | (exp << 20);
    return ((unsigned long long)hi << 32) | lo;
}
