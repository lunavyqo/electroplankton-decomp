// addr 0x0202b590 size 0xc

typedef struct {
    unsigned char pad[4];
    unsigned int field_4;
    unsigned int field_8;
} Unk_2b590;

void func_0202b590(Unk_2b590 *self, unsigned int a, unsigned int b) {
    self->field_4 = a;
    self->field_8 = b;
}
