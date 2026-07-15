// addr 0x02039c68 size 0x1e4
// NONMATCHING: G3 draw sketch (div~121); smulbb/mvnlt abs + regcount (sb) walls; size 480/484

void func_0200216c(short *out, short *a, short *b, short *c, short *d, int scale);
void func_0203b258(int a, int b, int c, int d, int e, int f, int g);
void func_020015a8(void *p);

typedef struct {
    int f0;
    int f4;
    int f8;
    int pad[7];
    void *f28;
} Inner;

typedef signed short s16;

void func_02039c68(void *self, int arg1, int color) {
    Inner *inner;
    short out0[3];
    short out1[3];
    int a, b, t, x, y;
    unsigned int *p;
    int sc;

    {
        short *p188 = (short *)((char *)self + 0x188);
        short *p1a0 = (short *)((char *)self + 0x1a0);
        inner = *(Inner **)((char *)self + 0x1c8);
        func_0200216c(out0, p188, p188 + 3, p188 + 6, p188 + 9, 0x800);
        func_0200216c(out1, p1a0, p1a0 + 3, p1a0 + 6, p1a0 + 9, 0x800);
    }

    b = out1[0];
    a = out0[0];
    y = out0[1];
    t = 0;
    if (a != b) {
        t = a - b;
        t = t + ((unsigned int)t >> 31);
        t = (t << 15) >> 16;
    }
    if (t < 0)
        t = -(s16)t;
    x = a - t;

    p = (unsigned int *)0x04000444;
    *p = 0;
    func_0203b258(1, arg1, 0x1000, inner->f8, inner->f4, 3, 3);
    x <<= 16;
    p = (unsigned int *)0x04000470;
    *p = (s16)(0x666 + (x >> 16));
    *p = y;
    *p = 0;
    p = (unsigned int *)0x0400046C;
    sc = 0x4cd;
    *p = sc;
    *p = sc;
    *p = 0x1000;
    p = (unsigned int *)0x04000480;
    *p = color;
    func_020015a8(inner->f28);
    p = (unsigned int *)0x04000448;
    *p = 1;

    y = out1[1];
    p = (unsigned int *)0x04000444;
    *p = 0;
    func_0203b258(1, arg1, 0x1000, inner->f8, inner->f4, 3, 3);
    p = (unsigned int *)0x04000470;
    *p = (s16)(0xfffff99a + (x >> 16));
    *p = y;
    *p = 0;
    p = (unsigned int *)0x0400046C;
    sc = 0x4cd;
    *p = sc;
    *p = sc;
    *p = 0x1000;
    p = (unsigned int *)0x04000480;
    *p = color;
    func_020015a8(inner->f28);
    p = (unsigned int *)0x04000448;
    *p = 1;
}
