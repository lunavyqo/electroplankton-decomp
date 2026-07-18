// addr 0x02017210 size 0xc

typedef struct {
    unsigned char pad[0xac];
    unsigned int field_ac;
} Unk_17210;

void func_02017210(Unk_17210 *self) {
    self->field_ac = 0;
}
