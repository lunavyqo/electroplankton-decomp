// addr 0x020198a0 size 0x18 — clear fields 0x88,0x8c,0xa4,0xa0

void func_020198a0(unsigned char *self) {
    *(int *)(self + 0x88) = 0;
    *(int *)(self + 0x8c) = 0;
    *(int *)(self + 0xa4) = 0;
    *(int *)(self + 0xa0) = 0;
}
