// addr 0x020423a8 size 0x20 — clear bit in data_02090fd8
extern unsigned int data_02090fd8;

void func_020423a8(unsigned int bit) {
    data_02090fd8 = data_02090fd8 & ~(1u << bit);
}
