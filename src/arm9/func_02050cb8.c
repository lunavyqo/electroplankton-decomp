// addr 0x02050cb8 size 0x78

int func_02050fe0(int a, unsigned short *out);

int func_02050cb8(int *out_a, int *out_b) {
    unsigned short flags;
    int ret;
    ret = func_02050fe0(0, &flags);
    if (ret != 0) {
        return ret;
    }
    if (out_a != 0) {
        *out_a = (flags & 8) != 0;
    }
    if (out_b != 0) {
        *out_b = (flags & 4) != 0;
    }
    return ret;
}
