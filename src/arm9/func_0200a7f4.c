// addr 0x0200a7f4 size 0xc

typedef struct {
    unsigned char pad[0x154];
    unsigned int field_154;
} UnkInner_154;

typedef struct {
    unsigned char pad[8];
    UnkInner_154 *inner;
} UnkOuter_a7f4;

unsigned int func_0200a7f4(UnkOuter_a7f4 *self) {
    return self->inner->field_154;
}
