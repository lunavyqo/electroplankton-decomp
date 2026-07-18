// addr 0x02044088 size 0xc

typedef struct {
    unsigned char pad[0x80];
    unsigned int field_80;
} Unk_44088;

void func_02044088(unsigned int unused0, unsigned int unused1, Unk_44088 *self) {
    self->field_80 = 0;
}
