// addr 0x020565ac size 0x40
// Soft-float float ordered compare → 0/1/2/3 (fused cmphs NaN check form).
//
// NONMATCHING: target uses cmphs + movlo/bxlo + bicmi/rsbmi (64B). (div=21)
// MWCC pure C not observed to emit cmphs/bicmi in this pin (same wall as 5669c).

int func_020565ac(int a, int b) {
    unsigned lim = 0xFF000000u;
    if (lim < ((unsigned)a << 1) || lim < ((unsigned)b << 1)) {
        return 3;
    }
    if (a < 0) {
        a &= ~0x80000000;
        a = -a;
    }
    if (b < 0) {
        b &= ~0x80000000;
        b = -b;
    }
    if (a == b) {
        return 0;
    }
    if (a < b) {
        return 1;
    }
    return 2;
}
