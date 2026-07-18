// addr 0x02026f58 size 0x20

void func_02026f58(void *self) {
    *(int *)((char *)self + 0x18) = 0;
    *(int *)((char *)self + 0x14) = 0x5a000;
    *(int *)((char *)self + 0x3c) = 0;
    *(int *)((char *)self + 0x44) = 1;
}
