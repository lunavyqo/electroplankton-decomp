// addr 0x020573b4 size 0x48
// _f_utof — unsigned int → float bits (round nearest, ties even-ish).
//
// NONMATCHING: target uses clz + sticky round tail (andeqs/addne). (div=34)
// __cntlzw helps but still diverges; (float)u cast is a bl stub only.

unsigned func_020573b4(unsigned x) {
    unsigned exp;
    unsigned round;
    unsigned m;
    if (x == 0u) {
        return 0u;
    }
    exp = 0x9eu;
    if ((int)x >= 0) {
        unsigned n = (unsigned)__cntlzw(x);
        x <<= n;
        exp -= n;
    }
    round = x & 0xffu;
    m = (x + x) >> 9;
    m |= exp << 23;
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
