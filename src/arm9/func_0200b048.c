// addr 0x0200b048 size 0xc

typedef struct {
    unsigned char pad[0x148];
    unsigned int field_148;
} UnkInner_148;

typedef struct {
    unsigned char pad[8];
    UnkInner_148 *inner;
} UnkOuter_b048;

void func_0200b048(UnkOuter_b048 *self, unsigned int v) {
    self->inner->field_148 = v;
}
