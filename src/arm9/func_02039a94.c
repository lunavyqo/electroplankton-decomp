// addr 0x02039a94 size 0x64
// NONMATCHING: halfword post-inc pair wall (div~29–31); target dual ldrh/strh [reg],#2 + subs/bne

extern unsigned short data_0206487c[];
extern unsigned short data_02064864[];

void func_02039a94(void *self) {
    unsigned short *src = data_0206487c;
    unsigned short *dst = (unsigned short *)((char *)self + 0x188);
    int n = 6;
    do {
        unsigned short a = *src;
        src += 1;
        unsigned short b = *src;
        src += 1;
        *dst = a;
        dst += 1;
        *dst = b;
        dst += 1;
    } while (--n);
    src = data_02064864;
    dst = (unsigned short *)((char *)self + 0x1a0);
    n = 6;
    do {
        unsigned short a = *src;
        src += 1;
        unsigned short b = *src;
        src += 1;
        *dst = a;
        dst += 1;
        *dst = b;
        dst += 1;
    } while (--n);
}
