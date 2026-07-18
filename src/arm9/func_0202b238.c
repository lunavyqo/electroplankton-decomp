// addr 0x0202b238 size 0xc

typedef struct {
    unsigned char pad[8];
    unsigned int field_8;
    unsigned int field_c;
    unsigned int field_10;
} Unk_2b238;

void func_0202b238(Unk_2b238 *self) {
    self->field_10 = self->field_8;
}
