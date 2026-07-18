// addr 0x0200a7cc size 0x28

typedef struct {
    unsigned char pad[0x154];
    int field_154;
    unsigned char pad2[0x160 - 0x158];
    int field_160;
} UnkInner_a7cc;

typedef struct {
    unsigned char pad[8];
    UnkInner_a7cc *inner;
} UnkOuter_a7cc;

int func_0200a7cc(UnkOuter_a7cc *self) {
    UnkInner_a7cc *inner = self->inner;
    if (inner->field_154 != 0 && inner->field_160 == 0) {
        return 1;
    }
    return 0;
}
