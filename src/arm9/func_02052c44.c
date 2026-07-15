
extern int data_0209504c;
extern unsigned short data_02095048[];
extern unsigned char data_02095060[];
extern unsigned char data_02095064[];
int func_020492bc(int a);
void func_02052930(unsigned short a, void *b);
void func_020529e4(void *a);
void func_0204aef4(void *a, int b);
void func_0204bd98(int a, void *b, void *c, int d);
void func_020529b0(void *a);
void func_02052908(unsigned short a, void *b);
void func_0204bf64(unsigned int a, void *b, int c);
void func_0204aec0(void);
void func_020528a4(unsigned int a);
void func_020004e4(int a);

void func_02052c44(void)
{
    volatile unsigned short *p300 = (volatile unsigned short *)0x04000300;
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    volatile unsigned short *p204 = (volatile unsigned short *)0x04000204;
    unsigned short *fw = (unsigned short *)0x027ffc30;
    int ret;
    int signbit;
    unsigned short saved_ime;
    int i;
    unsigned char buf0[8], buf8[8];
    unsigned short v;
    unsigned int p;
    unsigned char *base;
    unsigned char *q;

    if (data_0209504c != 0) return;
    data_0209504c = 1;
    if ((p300[0] & 1) == 0) return;

    ret = func_020492bc(0x40000);
    saved_ime = *ime;
    *ime = 1;
    func_02052930(data_02095048[1], buf0);
    signbit = (p204[0] & 0x8000) >> 15;
    func_020529e4(buf8);

    {
        unsigned short t = *p204;
        unsigned char *bp = data_02095060;
        *p204 = t & ~0x8000;
        func_0204aef4((char *)bp + 0x80, 0x40);
    }
    {
        unsigned char *bp = data_02095060;
        func_0204bd98(1, (void *)0x08000080, (char *)bp + 0x80, 0x40);
    }
    v = *p204;
    *p204 = (v & ~0x8000) | (signbit << 15);
    func_020529b0(buf8);
    func_02052908(data_02095048[1], buf0);

    base = data_02095060;
    *fw = *(unsigned short *)((char *)base + 0xbe);
    for (i = 0; i < 3; i++) {
        unsigned char *q2 = base + i;
        unsigned char b = q2[0xb5];
        unsigned int d = i + 0x2700000;
        d += 0xff000;
        ((unsigned char *)d)[0xc32] = b;
    }
    *(unsigned short *)((char *)fw + 6) = *(unsigned short *)((char *)base + 0xb0);
    *(unsigned int *)((char *)fw + 8) = *(unsigned int *)((char *)base + 0xac);

    func_0204bf64(0xffff0020, data_02095064, 0x9c);
    func_0204aec0();
    p = (unsigned int)data_02095060;
    p += 0xfe000000;
    p >>= 5;
    p <<= 6;
    p |= 1;
    func_020528a4(p);
    while (data_02095048[0] != 1)
        func_020004e4(1);
    v = *ime;
    *ime = saved_ime;
    func_020492bc(ret);
}
