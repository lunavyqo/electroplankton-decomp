// addr 0x020573fc size 0x48
// _f_itof — signed int → float bits.
//
// NONMATCHING: target abs via ands/rsbmi + clz normalize + round tail. (div=35)
// (float)i cast is only a bl stub into this runtime.

unsigned func_020573fc(int x) {
    unsigned sign = (unsigned)x & 0x80000000u;
    unsigned mag = (unsigned)x;
    unsigned exp;
    unsigned round;
    unsigned m;
    if ((int)sign < 0) {
        mag = (unsigned)(-x);
    }
    if (mag == 0u) {
        return 0u;
    }
    {
        unsigned n = (unsigned)__cntlzw(mag);
        mag <<= n;
        exp = 0x9eu - n;
    }
    round = mag & 0xffu;
    m = sign | ((mag + mag) >> 9) | (exp << 23);
    if (round == 0u) {
        return m;
    }
    if ((round & 0x80u) == 0u) {
        return m;
    }
    if ((round & 0x7fu) == 0u && (m & 1u) == 0u) {
        return m;
    }
    return m + 1u;
}
