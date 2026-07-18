// addr 0x0200b1e4 size 0x14

typedef struct {
    unsigned char pad[0xd4];
    unsigned char mid[0xc];
    unsigned int field_e0;
} UnkInner_b1e4;

typedef struct {
    unsigned char pad[8];
    UnkInner_b1e4 *inner;
} UnkOuter_b1e4;

void *func_0200b1e4(UnkOuter_b1e4 *self, unsigned int *out) {
    UnkInner_b1e4 *inner = self->inner;
    *out = inner->field_e0;
    return (unsigned char *)inner + 0xd4;
}
