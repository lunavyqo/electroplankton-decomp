// addr 0x020443f8 size 0x18 — swap data_02091bd8, return prior

extern unsigned int data_02091bd8;

unsigned int func_020443f8(unsigned int v) {
    unsigned int old = data_02091bd8;
    data_02091bd8 = v;
    return old;
}
