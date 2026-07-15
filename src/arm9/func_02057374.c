// addr 0x02057374 size 0x40
// _f_ftoul — IEEE float bits → unsigned long (soft-float runtime).
//
// NONMATCHING: target special-cases negative via lim cmp; overflow → ~0. (div=16)
// Pure C approximates control flow but not instruction selection.

unsigned func_02057374(unsigned f) {
    if (f & 0x80000000u) {
        unsigned lim = 0xFF000000u;
        if (lim >= (f << 1)) {
            return 0u;
        }
        return ~0u;
    }
    {
        int shift = 0x9e - (int)(f >> 23);
        if (shift < 0) {
            return ~0u;
        }
        return ((f << 8) | 0x80000000u) >> (unsigned)shift;
    }
}
