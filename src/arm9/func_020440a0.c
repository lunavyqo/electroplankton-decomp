// addr 0x020440a0 size 0x1c
extern unsigned char *data_02091bd8;

void func_020440a0(int idx, unsigned int val) {
    unsigned char *base = *(unsigned char **)(data_02091bd8 + 0x80);
    *(unsigned int *)(base + idx * 0x10 + 0x14) = val;
}
