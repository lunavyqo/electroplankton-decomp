// addr 0x02029ee8 size 0x18

void *func_02029ee8(unsigned char *self, int idx) {
    int n = *(int *)(self + 0x968);
    if (idx >= n) {
        idx = n - 1;
    }
    return self + 4 + (idx << 5);
}
