// addr 0x0200b038 size 0x10

typedef struct {
    unsigned char pad[0x124];
    unsigned int field_124;
    unsigned int field_128;
} UnkInner_b038;

typedef struct {
    unsigned char pad[8];
    UnkInner_b038 *inner;
} UnkOuter_b038;

void func_0200b038(UnkOuter_b038 *self, unsigned int a, unsigned int b) {
    UnkInner_b038 *inner = self->inner;
    inner->field_124 = a;
    inner->field_128 = b;
}
