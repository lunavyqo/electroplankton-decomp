// addr 0x02006154 size 0x108

typedef signed int s32;
typedef long long s64;

typedef struct {
    int field00;
    int field04;
    char pad08[0x3c];
    unsigned char field44;
    signed char field45;
    char pad46[2];
    int field48;
} Obj_02006154;

extern Obj_02006154 *data_0206f658;

void func_02042f94(void *p, int a, int b);
int func_02045d94(int a);
void func_02042ff4(void *p, int a);

/* Same two-step pattern as FX_MUL then >>12 (target does not collapse to >>24). */
#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

int func_02006154(int arg) {
    s32 tmp;
    s32 result;
    Obj_02006154 *obj;
    Obj_02006154 **pp = &data_0206f658;

    func_02042f94((char *)data_0206f658 + 4, 0, 1);
    func_02042f94((char *)data_0206f658 + 4, 1, 1);
    func_02042f94((char *)data_0206f658 + 4, 2, 1);
    func_02042f94((char *)data_0206f658 + 4, 3, 1);

    tmp = func_02045d94(arg << 12);
    result = FX_MUL(tmp, 0xe0590e);
    result = result >> 12;
    data_0206f658->field48 = result;

    obj = data_0206f658;
    func_02042ff4((char *)obj + 4, obj->field48);

    {
        Obj_02006154 *o = *pp;
        o->field45 = o->field45 + 1;
    }
    {
        Obj_02006154 *o = *pp;
        if (o->field45 >= 0x10) {
            o->field45 = 0;
        }
    }
    return data_0206f658->field45;
}
