// addr 0x020015e4 size 0x14

typedef struct {
    char pad[0x18];
    void *field18;
    void *field1c;
} Unk_020015e4;

void func_020490c8(void *self, void *a, void *b);

void func_020015e4(Unk_020015e4 *self) {
    func_020490c8(self, self->field1c, self->field18);
}
