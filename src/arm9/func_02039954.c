// addr 0x02039954 size 0xcc

void *func_02001084(int size, int align, int heapId);
int func_02039344(int x);
int func_020394cc(int x);
void *func_0203a748(int a, int b, int c, int d);

typedef struct {
    int v0;
    int v1;
    int v2;
    int pad_c;
    int field_10;
    int pad_14;
    int arr[10];
    int field_40;
    void *field_44;
    int field_48;
    int field_4c;
    int field_50;
} Obj54;

typedef struct {
    int x, y, z;
} Vec3;

Obj54 *func_02039954(int flag, int arg1, Vec3 *vec, int f10, int arg4, int arg5) {
    Obj54 *self;
    int t;
    int i;

    self = (Obj54 *)func_02001084(0x54, -4, -1);
    self->field_48 = arg5;
    self->field_4c = arg4;
    if (flag == 0) {
        self->field_50 = 0x10000;
    } else {
        self->field_50 = func_02039344(self->field_4c);
    }
    t = func_020394cc(arg4);
    self->field_44 = func_0203a748(flag, arg5, arg1, t);
    self->v0 = vec->x;
    self->v1 = vec->y;
    self->v2 = vec->z;
    self->field_10 = f10;
    for (i = 0; i < 10; i++) {
        self->arr[i] = (10 - (i + 1)) * 0x14000;
    }
    self->field_40 = 0;
    return self;
}
