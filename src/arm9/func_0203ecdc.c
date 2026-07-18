// addr 0x0203ecdc size 0x90

typedef long long s64;
typedef int s32;

int func_02045db0(int a, int b);

int func_0203ecdc(void *self) {
    int i;
    register int max_val;
    int thr;
    int z;
    int neg1;
    int off;
    int tbl;
    int v;
    int abs_v;
    int scaled;

    max_val = 0;
    i = max_val;
    thr = 0x80000;
    z = max_val;
    neg1 = -1;

    do {
        off = *(int *)((char *)self + 0x8c);
        tbl = *(int *)((char *)self + 0x6c);
        v = *(signed char *)(tbl + (i + off));
        abs_v = v << 12;
        if (abs_v < 0) {
            abs_v = abs_v * neg1;
        }
        scaled = func_02045db0(abs_v, thr);
        scaled = (s32)((((s64)scaled * 0xc8000) + 0x800LL) >> 12);
        i = i + 1;
        if (max_val < scaled) {
            max_val = scaled;
        }
    } while (i < 0x85);
    return max_val;
}
