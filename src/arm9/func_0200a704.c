// addr 0x0200a704 size 0xc

typedef struct {
    unsigned char pad[0x14c];
    unsigned int field_14c;
} UnkInner_14c;

typedef struct {
    unsigned char pad[8];
    UnkInner_14c *inner;
} UnkOuter_a704;

void func_0200a704(UnkOuter_a704 *self, unsigned int v) {
    self->inner->field_14c = v;
}
