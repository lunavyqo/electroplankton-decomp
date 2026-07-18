// addr 0x0204acd0 size 0x20 — init object header (two halfwords + fields)
void func_0204acd0(unsigned short *p, unsigned int a, unsigned int b) {
    p[0] = 0;
    p[1] = 0;
    *(unsigned int *)(p + 2) = a;
    *(unsigned int *)(p + 4) = b;
    *(unsigned int *)(p + 6) = 0;
    *(unsigned int *)(p + 8) = 0;
}
