// addr 0x020303d4 size 0x14
void func_020303d4(void *self) {
    *(int *)((char *)self + 0x40) = 0;
    *(short *)((char *)self + 0x46) = 0;
    *(int *)((char *)self + 0x3c) = 0;
}
