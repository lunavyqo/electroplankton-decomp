// addr 0x0200b06c size 0xc

typedef struct {
    unsigned char pad[0x13c];
    unsigned int field_13c;
} UnkInner_13c;

typedef struct {
    unsigned char pad[8];
    UnkInner_13c *inner;
} UnkOuter_b06c;

void func_0200b06c(UnkOuter_b06c *self, unsigned int v) {
    self->inner->field_13c = v;
}
