// addr 0x020106d4 size 0x20 — angle wrap (+delta, wrap if > 0x168000)

void func_020106d4(int *self, int delta) {
    *self = *self + delta;
    if (*self > 0x168000) {
        *self = *self - 0x168000;
    }
}
