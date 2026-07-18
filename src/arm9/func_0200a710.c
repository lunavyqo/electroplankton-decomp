// addr 0x0200a710 size 0xc

typedef struct {
    unsigned char pad[0x134];
    unsigned int field_134;
} UnkInner_134;

typedef struct {
    unsigned char pad[8];
    UnkInner_134 *inner;
} UnkOuter_a710;

void func_0200a710(UnkOuter_a710 *self, unsigned int v) {
    self->inner->field_134 = v;
}
