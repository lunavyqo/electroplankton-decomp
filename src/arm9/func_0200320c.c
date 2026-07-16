// NONMATCHING: thr hoisted once (retail reloads each iter); vol/n regalloc; asr vs lsr >>16; size 208 vs 212 (div=53)
// addr 0x0200320c size 0xd4

typedef signed short s16;

extern int data_0205d108;
extern int data_0205d10c;
extern int data_0205d110;
extern s16 data_0205d100;

void func_0200320c(s16 *a, s16 *b, unsigned int len, int flag, unsigned int *p) {
    unsigned int i;
    unsigned int n;
    unsigned int vol = *p;
    s16 thr;
    int nthr;
    s16 sa, sb;

    if (flag != 0) {
        return;
    }
    n = len >> 1;
    i = 0;
    if (n == 0) {
        goto done;
    }
    thr = data_0205d100;
    nthr = -thr;
    do {
        sa = a[i];
        if (sa > thr || sa < nthr || (sb = b[i]) > thr || sb < nthr) {
            if (vol > (unsigned)data_0205d110) {
                vol -= data_0205d10c;
            }
        } else {
            if (vol < 0x10000) {
                vol += data_0205d108;
            }
        }
        a[i] = (s16)((sa * (int)vol) >> 16);
        b[i] = (s16)((b[i] * (int)vol) >> 16);
        i++;
    } while (i < n);
done:
    *p = vol;
}
