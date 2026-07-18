// addr 0x02047574 size 0x1c
void func_02047574(unsigned int *out, unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    *out = a | 0x40 | (b << 8) | ((c | (d << 8)) << 16);
}
