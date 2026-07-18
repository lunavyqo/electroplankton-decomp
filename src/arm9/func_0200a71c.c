// addr 0x0200a71c size 0xc

typedef struct {
    unsigned char pad[0x15c];
    unsigned int field_15c;
} UnkInner_15c;

typedef struct {
    unsigned char pad[8];
    UnkInner_15c *inner;
} UnkOuter_a71c;

unsigned int func_0200a71c(UnkOuter_a71c *self) {
    return self->inner->field_15c;
}
