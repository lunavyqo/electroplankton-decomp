// addr 0x0201c468 size 0x258

typedef signed short s16;
typedef signed int s32;

typedef struct Inner {
    s16 field00;
    char pad02[0x10];
    s16 field12;
    char pad14[0x3c];
    s32 field50;
    s32 field54;
    char pad58[0x42c];
    s32 field484;
    char pad488[0x14];
    s32 field49c;
    char pad4a0[4];
    s32 field4a4;
    s32 field4a8;
} Inner;

typedef struct Outer {
    void *field00;
    s32 field04;
    char pad08[0xa];
    s16 field12;
    char pad14[0x20];
    Inner *field34;
} Outer;

extern char data_020675a8;
void func_020455e4(void *a, int b, int c);
void func_020193a4(void *a);
s32 func_02045db0(s32 a, s32 b);

// FX32 multiply: ((s64)a * b + 0x800) >> 12
#define FX_MUL(a, b) ((s32)(((long long)(a) * (b) + 0x800) >> 12))

void func_0201c468(Outer *self) {
    Inner *inner = self->field34;
    s32 counter;
    s32 tmp;

    if (inner->field4a8 != 0) {
        counter = inner->field4a4;
        if (counter >= 0 && counter < 5) {
            inner->field49c = FX_MUL(counter << 12, 0x4cd);
        } else if (counter >= 5 && counter < 8) {
            inner->field49c = 0x1800;
        } else if (counter >= 8 && counter < 0xd) {
            inner->field49c = FX_MUL((0xd - counter) << 12, 0x4cd);
        } else {
            inner->field49c = 0;
        }

        if (inner->field4a4 == 3) {
            func_020455e4(&data_020675a8, 5, 2);
        }

        inner->field4a4 = inner->field4a4 + 1;

        if (inner->field4a4 > 0x14) {
            inner->field4a8 = 0;
            inner->field4a4 = 0;
            func_020193a4(self->field00);
        }

        if (inner->field4a4 > 0xa) {
            inner->field484 = func_02045db0((0x14 - inner->field4a4) << 12, 0xa000);
        }
    } else {
        inner->field484 = 0x1000;
    }

    inner->field50 = FX_MUL(inner->field00, 0x666);
    inner->field50 = FX_MUL(inner->field50, self->field12);
    inner->field50 = inner->field50 + self->field04;

    inner->field54 = FX_MUL(inner->field12, self->field12);
    inner->field54 = inner->field54 + self->field04;

    tmp = FX_MUL(inner->field4a4 << 12, 0x2b8);
    inner->field50 = inner->field50 - tmp;

    tmp = FX_MUL(inner->field4a4 << 12, 0x2b8);
    inner->field54 = inner->field54 - tmp;
}
