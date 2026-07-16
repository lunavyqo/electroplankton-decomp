// NONMATCHING: clamp/loop codegen vs retail (size 568 vs 540, div~140)
// addr 0x02002d70 size 0x21c

typedef signed short s16;

typedef struct {
    int pad[3];
    struct {
        int field0c;
        int field10;
    } s[24];
} Slots;

void func_02002d70(s16 *a, s16 *b, unsigned int len, int flag, Slots *slots) {
    int n;
    int base;
    int i;
    int rem;
    int j;
    int idx;
    int va;
    int vb;
    int sat;

    if (flag != 0) {
        return;
    }

    n = (int)(len >> 1);
    base = 0;

    if (n > 0x18) {
        do {
            for (i = 0; i < 0x18; i++) {
                idx = base + i;
                va = (int)a[idx] + slots->s[i].field0c;
                vb = (int)b[idx] + slots->s[i].field10;
                sat = va;
                if (va < -0x8000) {
                    sat = -0x8000;
                } else if (va >= 0x8000) {
                    sat = 0x7fff;
                }
                a[idx] = (s16)sat;
                sat = vb;
                if (vb < -0x8000) {
                    sat = -0x8000;
                } else if (vb >= 0x8000) {
                    sat = 0x7fff;
                }
                b[idx] = (s16)sat;
                slots->s[i].field0c = (vb + 1) >> 2;
                slots->s[i].field10 = (va + 1) >> 2;
            }
            base += 0x18;
        } while (n > base + 0x18);
    }

    rem = n - base;
    if (rem > 0) {
        for (i = 0; i < rem; i++) {
            idx = base + i;
            va = (int)a[idx] + slots->s[i].field0c;
            vb = (int)b[idx] + slots->s[i].field10;
            sat = va;
            if (va < -0x8000) {
                sat = -0x8000;
            } else if (va >= 0x8000) {
                sat = 0x7fff;
            }
            a[idx] = (s16)sat;
            sat = vb;
            if (vb < -0x8000) {
                sat = -0x8000;
            } else if (vb >= 0x8000) {
                sat = 0x7fff;
            }
            b[idx] = (s16)sat;
        }
    }

    j = 0x18 - rem;
    if (j > 0) {
        for (i = 0; i < j; i++) {
            slots->s[i].field0c = slots->s[i + rem].field0c;
            slots->s[i].field10 = slots->s[i + rem].field10;
        }
    }

    if (rem <= 0) {
        return;
    }

    for (i = 0; i < rem; i++) {
        idx = base + i;
        slots->s[i + j].field0c = ((int)b[idx] + 1) >> 2;
        slots->s[i + j].field10 = ((int)a[idx] + 1) >> 2;
    }
}
