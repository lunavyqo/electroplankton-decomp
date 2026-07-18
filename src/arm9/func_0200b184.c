// addr 0x0200b184 size 0xc

typedef struct {
    unsigned char pad[0x164];
    unsigned int field_164;
} UnkInner_164;

typedef struct {
    unsigned char pad[8];
    UnkInner_164 *inner;
} UnkOuter_b184;

void func_0200b184(UnkOuter_b184 *self, unsigned int v) {
    self->inner->field_164 = v;
}
