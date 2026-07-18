// addr 0x02042428 size 0x24
extern unsigned int data_02090fd4;

int func_02042428(unsigned int mask) {
    unsigned int flags = data_02090fd4;
    if (mask & flags) {
        return 0;
    }
    data_02090fd4 |= mask;
    return 1;
}
