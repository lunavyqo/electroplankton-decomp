// addr 0x02025c84 size 0xc

typedef struct {
    unsigned char pad[0x1c];
    unsigned int field_1c;
} Unk_25c84;

void func_02025c84(unsigned int unused, Unk_25c84 *self) {
    self->field_1c = 0;
}
