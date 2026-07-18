// addr 0x0204bf1c size 0x18 — halfword fill, predicated strhlt loop

void func_0204bf1c(unsigned short val, unsigned char *dst, int nbytes) {
    int i = 0;
    for (;;) {
        if (i >= nbytes)
            return;
        *(unsigned short *)(dst + i) = val;
        i += 2;
    }
}
