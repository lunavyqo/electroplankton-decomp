// addr 0x020529b0 size 0x34

void func_020529b0(int *saved)
{
    unsigned short *p = (unsigned short *)0x04000204;
    int s = saved[0];
    unsigned short v = *p;
    *p = (s << 2) | (v & ~0xc);
    v = *p;
    s = saved[1];
    *p = (s << 4) | (v & ~0x10);
}
