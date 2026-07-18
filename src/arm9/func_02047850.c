// addr 0x02047850 size 0x1c
void func_02047850(unsigned int *self, unsigned char b, unsigned int c) {
    self[4] = 0;
    *(unsigned char *)self[0] = b;
    *(unsigned int *)self[1] = c;
}
