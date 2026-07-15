// addr 0x02052a2c size 0x11c

extern unsigned short data_02095048[];
void func_02052930(unsigned short a, void *b);
void func_020529e4(void *a);
void func_020529b0(void *a);
void func_02052908(unsigned short a, void *b);

int func_02052a2c(void)
{
    unsigned short *fw = (unsigned short *)0x027ffc30;
    unsigned char *cart = (unsigned char *)0x08000000;
    int ok = 1;
    unsigned char buf0[8];
    unsigned char buf8[8];
    unsigned char b;

    if (fw[0] == 0xffff)
        return 0;
    if (((unsigned)(*((unsigned char *)fw + 5) << 30) >> 31) == 1)
        return 0;

    func_02052930(data_02095048[1], buf0);
    func_020529e4(buf8);

    b = cart[0xb2];
    if (b == 0x96) {
        if (fw[0] != *(unsigned short *)(cart + 0xbe))
            goto fail;
    }
    if (b != 0x96) {
        if (fw[0] != *(unsigned short *)0x0801fffe)
            goto fail;
    }
    if (*(unsigned int *)((char *)fw + 8) != *(unsigned int *)(cart + 0xac)) {
        if ((unsigned)(*((unsigned char *)fw + 5) << 31) >> 31)
            goto fail;
    }
    goto done;
fail:
    ok = 0;
    *((unsigned char *)fw + 5) |= 2;
done:
    func_020529b0(buf8);
    func_02052908(data_02095048[1], buf0);
    return ok;
}
