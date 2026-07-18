// addr 0x020015f8 size 0xc

typedef struct {
    char pad[0x18];
    void *field18;
    void *field1c;
} Unk_020015f8;

void func_020015f8(Unk_020015f8 *self, void *a, void *b) {
    self->field1c = a;
    self->field18 = b;
}
