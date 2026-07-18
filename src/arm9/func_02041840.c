// addr 0x02041840 size 0x18 — zero fields, store halfword at +0xa
void func_02041840(void *p, unsigned short v) {
    *(int *)p = 0;
    *(int *)((char *)p + 4) = 0;
    *(unsigned short *)((char *)p + 8) = 0;
    *(unsigned short *)((char *)p + 10) = v;
}
