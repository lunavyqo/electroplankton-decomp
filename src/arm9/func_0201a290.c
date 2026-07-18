// addr 0x0201a290 size 0x20

void func_0201a290(void *self) {
    int *inner = *(int **)((char *)self + 0x34);
    if (inner[0x4a8 / 4] == 0) {
        inner[0x4a8 / 4] = 1;
        inner[0x4a4 / 4] = 0;
    }
}
