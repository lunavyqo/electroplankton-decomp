// addr 0x02039bac size 0xbc

void func_0203b258(int a, int b, int c, int d, int e, int f, int g);
void func_020015a8(void *p);

typedef struct {
    int f0;
    int f4;
    int pad[0xb];
    void *f34; /* 0x34 */
} Inner;

typedef struct {
    char pad[0x1c0];
    int f1c0;
    int pad2[1];
    Inner *inner; /* 0x1c8 */
} Obj;

void func_02039bac(Obj *self, int arg1, int color) {
    Inner *inner;
    unsigned int *push;
    unsigned int *trans;
    unsigned int *scale;
    unsigned int *poly;
    unsigned int *pop;
    unsigned int zero;
    unsigned int onek;
    void **slot;

    inner = self->inner;
    push = (unsigned int *)0x04000444;
    zero = 0;
    *push = zero;
    func_0203b258(1, arg1, 0x1000, inner->f0, inner->f4, 2, 2);
    trans = (unsigned int *)0x04000470;
    *trans = zero;
    *trans = 0x266;
    *trans = zero;
    scale = (unsigned int *)0x0400046C;
    onek = 0x1000;
    *scale = onek;
    *scale = onek;
    *scale = onek;
    poly = (unsigned int *)0x04000480;
    *poly = color;
    slot = (void **)((char *)inner->f34 + (self->f1c0 << 2) - 8);
    /* actually: add r0, r1, r0 lsl #2; ldr r0, [r0, #-8] */
    func_020015a8(*(void **)((int)inner->f34 + (self->f1c0 << 2) - 8));
    pop = (unsigned int *)0x04000448;
    *pop = 1;
}
