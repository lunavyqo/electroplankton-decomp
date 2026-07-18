// addr 0x02026ebc size 0xc

typedef struct {
    unsigned char pad[0x88];
    unsigned short field_88;
} UnkInner_26ebc;

typedef struct {
    unsigned char pad[0x4c];
    UnkInner_26ebc *inner;
} UnkOuter_26ebc;

void func_02026ebc(UnkOuter_26ebc *self, unsigned short v) {
    self->inner->field_88 = v;
}
