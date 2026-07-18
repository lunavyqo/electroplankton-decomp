// addr 0x0204782c size 0x24
void func_0204782c(unsigned int *self, unsigned char b, unsigned int c, unsigned int d) {
    self[4] = 0;
    *(unsigned char *)self[0] = b;
    *(unsigned int *)self[1] = c;
    *(unsigned int *)(self[1] + 4) = d;
}
