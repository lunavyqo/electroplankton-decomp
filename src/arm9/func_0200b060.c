// addr 0x0200b060 size 0xc

typedef struct {
    unsigned char pad[0x140];
    unsigned int field_140;
} UnkInner_140;

typedef struct {
    unsigned char pad[8];
    UnkInner_140 *inner;
} UnkOuter_b060;

void func_0200b060(UnkOuter_b060 *self, unsigned int v) {
    self->inner->field_140 = v;
}
