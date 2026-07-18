// addr 0x0201a2e0 size 0x24 — range check lo@+0x20 <= v < hi@+0x1c

int func_0201a2e0(int *self, int v) {
    int lo = self[0x20 / 4];
    int hi = self[0x1c / 4];
    if (lo <= v && v < hi) {
        return 1;
    }
    return 0;
}
