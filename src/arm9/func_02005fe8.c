// addr 0x02005fe8 size 0xa8

typedef signed int s32;
typedef long long s64;

typedef struct {
    int field00;
    int field04;
} Obj;

typedef struct {
    int field00;
    int pad04;
    int field08;
} S_020675cc;

extern int data_0206f65c;
extern S_020675cc data_020675cc;
extern Obj *data_0206f658;

void func_020430f0(void *p, int a);

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void func_02005fe8(void) {
    s32 tmp;
    if (data_0206f65c != 0) {
        return;
    }
    if (data_020675cc.field08 == 0) {
        return;
    }
    if (data_0206f658->field04 == 0) {
        return;
    }
    tmp = FX_MUL(data_020675cc.field00, 0x7f000);
    tmp = tmp >> 20;
    func_020430f0((char *)data_0206f658 + 4, tmp);
}
