// addr 0x0203e52c size 0x94

typedef signed short s16;

void func_0203e52c(void *self) {
    unsigned int zero = 0;
    unsigned int i;
    s16 *p;
    s16 z;

    *(unsigned int *)((char *)self + 0x4d0) = zero;
    *(unsigned int *)((char *)self + 0x4cc) = *(unsigned int *)((char *)self + 0x4d0);
    *(unsigned int *)((char *)self + 0x4c8) = *(unsigned int *)((char *)self + 0x4cc);
    *(unsigned int *)((char *)self + 0x4dc) = zero;
    *(unsigned int *)((char *)self + 0x4d8) = *(unsigned int *)((char *)self + 0x4dc);
    *(unsigned int *)((char *)self + 0x4d4) = *(unsigned int *)((char *)self + 0x4d8);

    i = zero;
    p = (s16 *)self;
    z = 0;
    do {
        p[2] = z;
        i = i + 1;
        p[1] = p[2];
        p[0] = p[1];
        p[5] = z;
        p[4] = p[5];
        p[3] = p[4];
        p[8] = z;
        p[7] = p[8];
        p[6] = p[7];
        p[11] = z;
        p[10] = p[11];
        p[9] = p[10];
        p = p + 12;
    } while (i < 6);
}
