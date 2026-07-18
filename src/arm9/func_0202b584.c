// addr 0x0202b584 size 0xc

typedef struct {
    unsigned char pad[0x10];
    unsigned short field_10;
    unsigned short field_12;
} Unk_2b584;

void func_0202b584(Unk_2b584 *self, unsigned short a, unsigned short b) {
    self->field_10 = a;
    self->field_12 = b;
}
