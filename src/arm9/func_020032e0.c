// addr 0x020032e0 size 0x8c

typedef signed short s16;

void func_020032e0(s16 *a, s16 *b, unsigned int len, int flag, s16 *p) {
    unsigned int i;
    unsigned int n;
    int t;
    s16 *state = p;

    if (flag != 0) {
        return;
    }
    n = len >> 1;
    i = 0;
    if (n == 0) {
        return;
    }
    do {
        t = a[i] - state[0];
        a[i] = (s16)(t / 2);
        state[0] = a[i];
        t = b[i] - state[1];
        b[i] = (s16)(t / 2);
        state[1] = b[i];
        i++;
    } while (i < n);
}
