// addr 0x020397e4 size 0x88
// NONMATCHING: regalloc wall (div=13): push/zero as lr/r4 vs target r4/r2; size exact 136

void func_0203a058(int a, void *b);

typedef struct {
    int x, y, z, pad, scale;
    int pad2[12];
    void *field_44;
    int field_48;
} Obj;

void func_020397e4(Obj *self) {
    unsigned int *push = (unsigned int *)0x04000444;
    unsigned int zero = 0;
    unsigned int *trans = (unsigned int *)0x04000470;
    unsigned int *scale = (unsigned int *)0x0400046C;
    unsigned int s, x, y, z;

    *push = zero;
    z = self->z;
    y = self->y;
    x = self->x;
    *trans = x;
    *trans = y;
    *trans = z;
    s = self->scale;
    *scale = s;
    *scale = s;
    *scale = 0x1000;
    *push = zero;
    func_0203a058(self->field_48, self->field_44);
    {
        unsigned int *pop = (unsigned int *)0x04000448;
        *pop = 1;
        *pop = 1;
    }
}
