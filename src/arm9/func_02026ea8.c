// addr 0x02026ea8 size 0xc

typedef struct {
    unsigned char pad[0x84];
    unsigned int field_84;
} UnkInner_84;

typedef struct {
    unsigned char pad[0x4c];
    UnkInner_84 *inner;
} UnkOuter_26ea8;

void func_02026ea8(UnkOuter_26ea8 *self, unsigned int v) {
    self->inner->field_84 = v;
}
