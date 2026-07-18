// addr 0x02022038 size 0x24

void func_02022038(unsigned char *self) {
    *(int *)self = 0;
    *(unsigned short *)(self + 6) = 600;
    *(unsigned short *)(self + 4) = 0;
    self[8] = 0;
    *(unsigned short *)(self + 10) = 0;
    self[9] = 0;
}
