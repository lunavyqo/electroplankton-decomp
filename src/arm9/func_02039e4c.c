// addr 0x02039e4c size 0x20c
// NONMATCHING: G3 draw sibling (div~131); smulbb abs wall; scale 333/4cd; tex self+0x1bc; size 520/524

void func_0200216c(short *out, short *a, short *b, short *c, short *d, int scale);
void func_0203b258(int a, int b, int c, int d, int e, int f, int g);
void func_020015a8(void *p);

typedef struct {
    int f0;
    int f4;
    int pad[0xa];
    void *f30;
} Inner;

typedef signed short s16;

void func_02039e4c(void *self, int arg1, int color) {
    Inner *inner;
    short out0[3];
    short out1[3];
    int a, b, t, x, y;
    unsigned int *p;
    int idx;

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
    if (a != b) {
        t = a - b;
        t = t + ((unsigned int)t >> 31);
        t = (t << 15) >> 16;
    } else {
        t = 0;
    }
    if (t < 0)
        t = -(s16)t;
    x = a - t;

    p = (unsigned int *)0x04000444;
    *p = 0;
    func_0203b258(1, arg1, 0x1000, inner->f0, inner->f4, 2, 2);
    x <<= 16;
    p = (unsigned int *)0x04000470;
    *p = (s16)(0x666 + (x >> 16));
    *p = y;
    *p = 0;
    p = (unsigned int *)0x0400046C;
    *p = 0x333;
    *p = 0x4cd;
    *p = 0x1000;
    p = (unsigned int *)0x04000480;
    *p = color;
    idx = *(int *)((char *)self + 0x1bc);
    func_020015a8(*((void **)((int)inner->f30 + (idx << 2) - 8)));
    p = (unsigned int *)0x04000448;
    *p = 1;

    y = out1[1];
    p = (unsigned int *)0x04000444;
    *p = 0;
    func_0203b258(1, arg1, 0x1000, inner->f0, inner->f4, 2, 2);
    p = (unsigned int *)0x04000470;
    *p = (s16)(0xfffff99a + (x >> 16));
    *p = y;
    *p = 0;
    p = (unsigned int *)0x0400046C;
    *p = 0x333;
    *p = 0x4cd;
    *p = 0x1000;
    p = (unsigned int *)0x04000480;
    *p = color;
    idx = *(int *)((char *)self + 0x1bc);
    func_020015a8(*((void **)((int)inner->f30 + (idx << 2) - 8)));
    p = (unsigned int *)0x04000448;
    *p = 1;
}
