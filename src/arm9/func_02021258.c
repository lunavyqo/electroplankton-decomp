// addr 0x02021258 size 0x10

unsigned int func_02021258(void *base, int idx) {
    return *(unsigned int *)((char *)base + idx * 0x18 + 0x18);
}
