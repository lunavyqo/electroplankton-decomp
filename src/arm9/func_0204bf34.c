// addr 0x0204bf34 size 0x1c — halfword copy, predicated ldrhlt/strhlt loop

void func_0204bf34(unsigned char *src, unsigned char *dst, int nbytes) {
    int i = 0;
    for (;;) {
        if (i >= nbytes)
            return;
        *(unsigned short *)(dst + i) = *(unsigned short *)(src + i);
        i += 2;
    }
}
