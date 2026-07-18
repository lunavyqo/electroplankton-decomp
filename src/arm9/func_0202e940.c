// addr 0x0202e940 size 0x10

void func_0202e978(void *self, unsigned int a);

typedef struct {
    unsigned char pad[0x10];
    unsigned int field_10;
} Unk_2e940;

void func_0202e940(Unk_2e940 *self) {
    func_0202e978(self, self->field_10);
}
