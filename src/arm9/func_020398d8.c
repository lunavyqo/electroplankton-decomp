// addr 0x020398d8 size 0x5c

int func_020394cc(int x);
void func_0203a668(int a, int b, int c, int d);

typedef struct {
    int v0;
    int v1;
    int v2;
    int pad_c;
    int field_10;
    int pad_14[0xc]; /* 0x14..0x43 */
    int field_44;
    int field_48;
    int field_4c;
    int field_50;
} Obj;

typedef struct {
    int x, y, z;
} Vec3;

void func_020398d8(Obj *self, Vec3 *vec, int f10, int f50, int f4c, int arg5) {
    int t;
    self->field_4c = f4c;
    self->field_50 = f50;
    t = func_020394cc(self->field_4c);
    func_0203a668(self->field_48, self->field_44, t, arg5);
    self->v0 = vec->x;
    self->v1 = vec->y;
    self->v2 = vec->z;
    self->field_10 = f10;
}
