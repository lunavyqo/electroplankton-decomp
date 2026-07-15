// addr 0x02057340 size 0x34
// _f_ftol — IEEE float bits → signed long (soft-float runtime).
//
// NONMATCHING: hand-written runtime sequence (bic/subs/ble/orr/lsr/rsbmi; (div=12)
// overflow via mvn asr#31). Pure C bit-twiddle is same-size-ish but wrong insn
// selection; (int)float cast only emits a bl stub into this routine.

int func_02057340(unsigned f) {
    unsigned mag = f & ~0x80000000u;
    int shift = 0x9e - (int)(mag >> 23);
    if (shift <= 0) {
        /* sign-dependent overflow: INT_MAX or 0x80000000 */
        return (int)(~((int)f >> 31) + 0x80000000);
    }
    {
        unsigned mant = (mag << 8) | 0x80000000u;
        unsigned res = mant >> (unsigned)shift;
        if ((int)f < 0) {
            return -(int)res;
        }
        return (int)res;
    }
}
