// addr 0x0202f568 size 0x10

typedef struct {
    unsigned char pad[0x28];
    unsigned int field_28;
    unsigned int pad_2c;
    unsigned int field_30;
} Unk_2f568;

void func_0202f568(Unk_2f568 *self) {
    self->field_30 = 1;
    self->field_28 = 1;
}
