// addr 0x0202b4fc size 0xc

typedef struct {
    unsigned char pad[0xe];
    unsigned char field_e;
} UnkInner_2b4fc;

typedef struct {
    UnkInner_2b4fc *inner;
} UnkOuter_2b4fc;

unsigned char func_0202b4fc(UnkOuter_2b4fc *self) {
    return self->inner->field_e;
}
