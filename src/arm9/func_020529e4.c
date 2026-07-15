// addr 0x020529e4 size 0x48

void func_020529e4(int *out)
{
    volatile unsigned short *p = (volatile unsigned short *)0x04000204;
    unsigned short v;

    v = *p;
    out[0] = (v & 0xc) >> 2;
    v = *p;
    out[1] = (v & 0x10) >> 4;
    v = *p;
    *p = (v & ~0xc) | 0xc;
    v = *p;
    *p = v & ~0x10;
}
