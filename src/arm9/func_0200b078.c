// addr 0x0200b078 size 0xc

typedef struct {
    unsigned char pad[0x138];
    unsigned int field_138;
} UnkInner_138;

typedef struct {
    unsigned char pad[8];
    UnkInner_138 *inner;
} UnkOuter_b078;

void func_0200b078(UnkOuter_b078 *self, unsigned int v) {
    self->inner->field_138 = v;
}
