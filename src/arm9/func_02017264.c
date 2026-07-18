// addr 0x02017264 size 0x20 — negate halfword; if flag==0 use 0x8000-x

unsigned short func_02017264(unsigned short x, int flag) {
    if (flag != 0) {
        return (unsigned short)(-((int)x));
    } else {
        return (unsigned short)(0x8000 - x);
    }
}
