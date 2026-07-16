// addr 0x02003170 size 0x9c

typedef signed short s16;

void func_02003170(s16 *a, s16 *b, unsigned int len, int flag, s16 *p) {
    unsigned int i;
    unsigned int n;
    s16 lim = *p;

    if (flag != 0) {
        return;
    }
    n = len >> 1;
    if (lim < 0) {
        lim = (s16)(-lim);
    }
    i = 0;
    if (i >= n) {
        return;
    }
    do {
        if (a[i] > lim) {
            a[i] = lim;
        }
        if (a[i] < -(int)lim) {
            a[i] = (s16)(-(int)lim);
        }
        if (b[i] > lim) {
            b[i] = lim;
        }
        if (b[i] < -(int)lim) {
            b[i] = (s16)(-(int)lim);
        }
        i++;
    } while (i < n);
}
