// addr 0x0203f160 size 0x5c

void func_0203f160(int *self) {
    int off_a = 0x438;
    int off_b = 0x43c;
    int *pa;
    int *pb;
    self[0x438 / 4] = self[0x438 / 4] + 0x3000;
    pa = (int *)((char *)self + off_a);
    if (self[0x438 / 4] >= 0x168000) {
        *pa = *pa - 0x168000;
    }
    self[0x43c / 4] = self[0x43c / 4] + 0x2000;
    pb = (int *)((char *)self + off_b);
    if (self[0x43c / 4] >= 0x168000) {
        *pb = *pb - 0x168000;
    }
}
