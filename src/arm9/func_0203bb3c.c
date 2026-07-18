// addr 0x0203bb3c size 0x24

extern int *data_02090f88;

void func_0203bb3c(void) {
    int *p = data_02090f88;
    *(int *)((char *)p + 0x40c) = *(int *)((char *)p + 0x408);
    *(int *)((char *)p + 0x408) = *(int *)((char *)p + 0x408) + 1;
}
