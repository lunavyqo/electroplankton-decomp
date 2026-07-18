// addr 0x02024b4c size 0x8c8
// Init plankton sub-object positions from mode at outer+0xd8

typedef signed int s32;
typedef signed short s16;
typedef unsigned short u16;
typedef long long s64;

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    s32 field00;
    s32 field04;
    char pad08[4];
    s32 field0c;
    s32 field10;
    char pad14[0x1c];
    unsigned char field30;
    unsigned char field31;
    u16 field32;
    u16 field34;
    u16 field36;
    s32 field38;
    s32 field3c;
} SubObj;

typedef struct {
    char pad00[0x34];
    SubObj *items[0x40];
} Outer;

extern Outer *data_02090f1c;
extern s16 data_0205872c[];

s32 func_020024e4(s32 a, s32 b);
u16 func_02002528(s32 a, s32 b);

double func_02055bd0(s32 x);
s32 func_02055af0(double x);
double func_02055c10(double a, double b);
double func_020556d4(double a, double b);
double func_02055f8c(double a, double b);
s32 func_02056cb0(double a, double b);

void func_02024b4c(void)
{
    unsigned int i;
    s32 si;
    s32 idx;
    s32 vx, vy;
    s32 tmp;
    double d;
    double t;
    int mode;

    mode = *(unsigned char *)((char *)data_02090f1c + 0xd8);

    if (mode == 0) {
        goto mode0;
    }
    if (mode == 1) {
        goto mode1;
    }
    if (mode == 2) {
        goto mode2;
    }
    return;

mode0:
    i = 0;
    do {
        si = (s32)i;
        d = func_02055bd0(si % 7);
        d = func_02055c10(1.142, d);
        d = func_020556d4(-3.5, d);
        if (func_02056cb0(d, 0.0) != 0) {
            t = func_02055c10(4096.0, d);
            t = func_020556d4(0.5, t);
        } else {
            t = func_02055c10(4096.0, d);
            t = func_02055f8c(t, 0.5);
        }
        data_02090f1c->items[i]->field0c = func_02055af0(t);
        data_02090f1c->items[i]->field00 = data_02090f1c->items[i]->field0c;

        d = func_02055bd0(si / 7);
        d = func_02055c10(1.25, d);
        d = func_02055f8c(2.5, d);
        if (func_02056cb0(d, 0.0) != 0) {
            t = func_02055c10(4096.0, d);
            t = func_020556d4(0.5, t);
        } else {
            t = func_02055c10(4096.0, d);
            t = func_02055f8c(t, 0.5);
        }
        data_02090f1c->items[i]->field10 = func_02055af0(t);
        data_02090f1c->items[i]->field04 = data_02090f1c->items[i]->field10;

        data_02090f1c->items[i]->field38 = func_020024e4(0x13f, 0x27f);
        data_02090f1c->items[i]->field3c = data_02090f1c->items[i]->field38;
        data_02090f1c->items[i]->field31 = 0;
        data_02090f1c->items[i]->field30 = 0;
        data_02090f1c->items[i]->field32 = 0;
        data_02090f1c->items[i]->field34 = func_02002528(0, 0xffff);
        data_02090f1c->items[i]->field36 = func_02002528(0x2d8, 0x666);

        i = (unsigned short)(i + 1);
    } while (i < 0x23);
    return;

mode1:
    i = 0;
    do {
        idx = (((s32)(i * 0xfff0)) / 23) >> 4;
        vx = FX_MUL((s32)data_0205872c[idx * 2], 0x2666);
        data_02090f1c->items[i]->field0c = vx;
        data_02090f1c->items[i]->field00 = data_02090f1c->items[i]->field0c;

        {
            s32 ys = (s32)data_0205872c[idx * 2 + 1];
            s64 p = (s64)ys * 0x2666;
            s32 yfx = (s32)((p + 0x800) >> 12);
            p = (s64)yfx * (s32)0xfffff000;
            data_02090f1c->items[i]->field10 = (s32)((p + 0x800) >> 12);
        }
        data_02090f1c->items[i]->field04 = data_02090f1c->items[i]->field10;

        data_02090f1c->items[i]->field38 = func_020024e4(0x13f, 0x27f);
        data_02090f1c->items[i]->field3c = data_02090f1c->items[i]->field38;
        data_02090f1c->items[i]->field31 = 0;
        data_02090f1c->items[i]->field30 = 0;
        data_02090f1c->items[i]->field32 = 0;
        data_02090f1c->items[i]->field34 = func_02002528(0, 0xffff);
        data_02090f1c->items[i]->field36 = func_02002528(0x2d8, 0x666);

        i = (unsigned short)(i + 1);
    } while (i < 0x17);

    i = 0;
    do {
        idx = (((s32)(i * 0xfff0)) / 12) >> 4;
        vx = FX_MUL((s32)data_0205872c[idx * 2], 0x1333);
        data_02090f1c->items[i + 0x17]->field0c = vx;
        data_02090f1c->items[i + 0x17]->field00 = data_02090f1c->items[i + 0x17]->field0c;

        vy = FX_MUL((s32)data_0205872c[idx * 2 + 1], 0x1333);
        vy = FX_MUL(vy, (s32)0xfffff000);
        data_02090f1c->items[i + 0x17]->field10 = vy;
        data_02090f1c->items[i + 0x17]->field04 = data_02090f1c->items[i + 0x17]->field10;

        tmp = func_020024e4(0x13f, 0x27f);
        data_02090f1c->items[i + 0x17]->field38 = FX_MUL(tmp, 0x99a);
        data_02090f1c->items[i + 0x17]->field3c = data_02090f1c->items[i + 0x17]->field38;
        data_02090f1c->items[i + 0x17]->field31 = 0;
        data_02090f1c->items[i + 0x17]->field30 = 0;
        data_02090f1c->items[i + 0x17]->field32 = 0;
        data_02090f1c->items[i + 0x17]->field34 = func_02002528(0, 0xffff);
        data_02090f1c->items[i + 0x17]->field36 = func_02002528(0x2d8, 0x666);

        i = (unsigned short)(i + 1);
    } while ((s32)i < 0xc);
    return;

mode2:
    i = 0;
    do {
        idx = (((s32)(i * 0xfff0)) / 35) >> 4;
        vx = FX_MUL((s32)data_0205872c[idx * 2], 0x3333);
        data_02090f1c->items[i]->field0c = vx;
        data_02090f1c->items[i]->field00 = data_02090f1c->items[i]->field0c;

        {
            s32 ys = (s32)data_0205872c[idx * 2 + 1];
            s64 p = (s64)ys * 0x2666;
            s32 yfx = (s32)((p + 0x800) >> 12);
            p = (s64)yfx * (s32)0xfffff000;
            data_02090f1c->items[i]->field10 = (s32)((p + 0x800) >> 12);
        }
        data_02090f1c->items[i]->field04 = data_02090f1c->items[i]->field10;

        data_02090f1c->items[i]->field38 = func_020024e4(0x13f, 0x27f);
        data_02090f1c->items[i]->field3c = data_02090f1c->items[i]->field38;
        data_02090f1c->items[i]->field31 = 0;
        data_02090f1c->items[i]->field30 = 0;

        i = (unsigned short)(i + 1);
    } while (i < 0x23);
    return;
}
