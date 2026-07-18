// addr 0x02044094 size 0xc

typedef struct {
    unsigned char pad[0x88];
    unsigned int field_88;
} Unk_44094;

void func_02044094(unsigned int unused0, unsigned int unused1, Unk_44094 *self) {
    self->field_88 = 0;
}
