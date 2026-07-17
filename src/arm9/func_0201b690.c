// addr 0x0201b690 size 0x8c

typedef signed short s16;
typedef signed int s32;

typedef struct Inner {
    char pad00[0x42];
    s16 field42;
    s16 field44;
    s16 field46;
    char pad48[0x43c];
    s32 field484;
    s16 field488;
    s16 field48a[3];
    s32 field490[3];
    s32 field49c;
    s32 pad4a0;
    s32 field4a4;
    s32 field4a8;
    void *field4ac;
} Inner;

void *func_02001084(int size, int align, int heapId);

Inner *func_0201b690(void *owner) {
    Inner *p = (Inner *)func_02001084(0x4b0, -4, -1);
    int i;
    s32 zero = 0;
    s32 one_fx = 0x1000;

    p->field4ac = owner;
    for (i = 0; i < 3; i++) {
        p->field48a[i] = (s16)zero;
        p->field490[i] = one_fx;
    }
    p->field488 = (s16)zero;
    p->field42 = 0x4bff;
    p->field44 = 0x7ff2;
    p->field46 = 0x7fff;
    p->field49c = zero;
    p->field4a4 = zero;
    p->field4a8 = zero;
    p->field484 = one_fx;
    return p;
}
