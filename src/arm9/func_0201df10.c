// addr 0x0201df10 size 0xc

typedef struct {
    unsigned char pad[8];
    unsigned short field_8;
} UnkInner_1df10;

typedef struct {
    unsigned char pad[0x18];
    UnkInner_1df10 *inner;
} UnkOuter_1df10;

unsigned short func_0201df10(UnkOuter_1df10 *self) {
    return self->inner->field_8;
}
