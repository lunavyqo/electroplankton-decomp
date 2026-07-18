// addr 0x0200a728 size 0xc

typedef struct {
    unsigned char pad[0x11c];
    unsigned int field_11c;
} UnkInner_11c;

typedef struct {
    unsigned char pad[8];
    UnkInner_11c *inner;
} UnkOuter_a728;

unsigned int func_0200a728(UnkOuter_a728 *self) {
    return self->inner->field_11c;
}
