// addr 0x0200b178 size 0xc

typedef struct {
    unsigned char pad[0xe4];
    unsigned int field_e4;
} UnkInner_e4;

typedef struct {
    unsigned char pad[8];
    UnkInner_e4 *inner;
} UnkOuter_b178;

void func_0200b178(UnkOuter_b178 *self, unsigned int v) {
    self->inner->field_e4 = v;
}
