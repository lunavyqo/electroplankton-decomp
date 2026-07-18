// addr 0x02047550 size 0x24
void func_02047550(unsigned short *out, unsigned short flags, int val) {
    if (val < 0) {
        *out = flags | 0xc0;
        out[2] = (unsigned short)(-val);
    } else {
        *out = flags | 0x80;
        out[2] = (unsigned short)val;
    }
}
