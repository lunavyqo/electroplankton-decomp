// Clamp x to [lo, hi], swapping lo/hi if needed.
// addr 0x020092ac size 0x54

void func_02009334(int *a, int *b);

int func_020092ac(int x, int lo, int hi) {
    int ret;

    if (lo > hi) {
        func_02009334(&lo, &hi);
    }
    if (x < lo) {
        return lo;
    }
    ret = hi;
    if (x <= hi) {
        ret = x;
    }
    return ret;
}
