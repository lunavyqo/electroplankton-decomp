// addr 0x0200336c size 0x84

typedef signed short s16;

void func_0200336c(s16 *a, s16 *b, unsigned int len, int flag, s16 *p) {
    unsigned int i;
    unsigned int n;
    int t;
    s16 s;
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
        s = a[i];
        t = s - state[0];
        state[0] = s;
        a[i] = (s16)(t / 2);
        s = b[i];
        t = s - state[1];
        state[1] = s;
        b[i] = (s16)(t / 2);
        i++;
    } while (i < n);
}
