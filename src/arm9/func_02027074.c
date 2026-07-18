// addr 0x02027074 size 0x18 — tail to func_02027230(p+0x4c, p+0x48)

void func_02027230(void *a, void *b);

void func_02027074(unsigned char *p) {
    func_02027230(*(void **)(p + 0x4c), *(void **)(p + 0x48));
}
