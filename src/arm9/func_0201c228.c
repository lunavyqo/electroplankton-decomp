// addr 0x0201c228 size 0x88

typedef signed int s32;
typedef struct Outer {
    void *field00;
    char pad04[0x28];
    s32 field2c;
    char pad30[4];
    void *field34;
} Outer;
typedef struct Inner {
    char pad00[0x484];
    s32 field484;
    char pad488[0x14];
    s32 field49c;
    char pad4a0[4];
    s32 field4a4;
    s32 field4a8;
} Inner;
void func_0201abb0(void *inner, void *obj);
void func_0204b7d4(void);
void func_0201c228(Outer *self, s32 mode) {
    Inner *inner = (Inner *)self->field34;
    inner->field49c = 0;
    inner->field484 = 0x1000;
    inner->field4a8 = 0;
    inner->field4a4 = 0;
    if (self->field2c == mode) return;
    self->field2c = mode;
    switch (self->field2c) {
    case 0:
        func_0201abb0(self->field34, self->field00);
        break;
    case 1:
        break;
    default:
        func_0204b7d4();
        break;
    }
}
