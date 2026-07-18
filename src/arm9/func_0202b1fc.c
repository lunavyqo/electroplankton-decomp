// addr 0x0202b1fc size 0x10

void func_0202b244(void *self, unsigned int a);

typedef struct {
    unsigned char pad[0x14];
    unsigned int field_14;
} Unk_2b1fc;

void func_0202b1fc(Unk_2b1fc *self) {
    func_0202b244(self, self->field_14);
}
