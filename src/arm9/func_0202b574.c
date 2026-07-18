// addr 0x0202b574 size 0x10

typedef struct {
    unsigned char pad[0x10];
    unsigned short field_10;
    unsigned short field_12;
} Unk_2b574;

unsigned int func_0202b574(Unk_2b574 *self) {
    unsigned int result = self->field_12;
    return (result << 16) | self->field_10;
}
