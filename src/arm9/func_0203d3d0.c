// addr 0x0203d3d0 size 0xc

typedef struct {
    unsigned char pad[0xc];
    unsigned int field_c;
    unsigned int field_10;
} Unk_3d3d0;

void func_0203d3d0(Unk_3d3d0 *self, unsigned int a, unsigned int b) {
    self->field_c = a;
    self->field_10 = b;
}
