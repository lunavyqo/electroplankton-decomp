// addr 0x020025e8 size 0x24 — increment counter, return min(old&0xff, 0x3f) with hi clamp on new

extern unsigned int data_02067598;

unsigned int func_020025e8(void) {
    unsigned int old = data_02067598;
    unsigned int neu = old + 1;
    unsigned int ret;
    data_02067598 = neu;
    ret = old & 0xff;
    if (neu > 0x3f) {
        ret = 0x3f;
    }
    return ret;
}
