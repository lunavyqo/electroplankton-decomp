// addr 0x02039af8 size 0xb4

void func_0203b258(int a, int b, int c, int d, int e, int f, int g);
void func_020015a8(void *p);

typedef struct {
    int f0;
    int f4;
    int pad[1];
    int fc; /* 0xc */
    int pad2[7];
    void *f2c; /* 0x2c */
} Inner;

typedef struct {
    char pad[0x1c8];
    Inner *inner;
} Obj;

void func_02039af8(Obj *self, int arg1, int color) {
    Inner *inner;
    unsigned int *push;
    unsigned int *trans;
    unsigned int *scale;
    unsigned int *poly;
    unsigned int *pop;
    unsigned int zero;
    unsigned int s;

    inner = self->inner;
    push = (unsigned int *)0x04000444;
    zero = 0;
    *push = zero;
    func_0203b258(1, arg1, 0x1000, inner->fc, inner->f4, 3, 3);
    trans = (unsigned int *)0x04000470;
    *trans = zero;
    *trans = 0xFFFFFAE1;
    *trans = zero;
    scale = (unsigned int *)0x0400046C;
    s = 0x666;
    *scale = s;
    *scale = s;
    *scale = 0x1000;
    poly = (unsigned int *)0x04000480;
    *poly = color;
    func_020015a8(inner->f2c);
    pop = (unsigned int *)0x04000448;
    *pop = 1;
}
