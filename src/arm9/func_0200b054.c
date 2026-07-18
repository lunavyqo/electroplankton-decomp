// addr 0x0200b054 size 0xc

typedef struct {
    unsigned char pad[0x144];
    unsigned int field_144;
} UnkInner_144;

typedef struct {
    unsigned char pad[8];
    UnkInner_144 *inner;
} UnkOuter_b054;

void func_0200b054(UnkOuter_b054 *self, unsigned int v) {
    self->inner->field_144 = v;
}
