// addr 0x02046444 size 0x1c
void func_02046444(unsigned int bits) {
    volatile unsigned int *p = (volatile unsigned int *)0x04001000;
    *p = (*p & ~7u) | bits;
}
