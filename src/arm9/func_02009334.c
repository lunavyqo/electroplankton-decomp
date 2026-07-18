// addr 0x02009334 size 0x14 — swap two ints

void func_02009334(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
