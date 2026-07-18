// addr 0x02025c90 size 0xc

typedef struct {
    unsigned char pad[0x1c];
    unsigned int field_1c;
} Unk_25c90;

void func_02025c90(unsigned int unused, Unk_25c90 *self) {
    self->field_1c = 1;
}
