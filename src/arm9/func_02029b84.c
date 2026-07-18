// addr 0x02029b84 size 0xc

typedef struct {
    unsigned char pad[0x9a8];
    unsigned int field_9a8;
} Unk_29b84;

void func_02029b84(Unk_29b84 *self) {
    self->field_9a8 = 2;
}
