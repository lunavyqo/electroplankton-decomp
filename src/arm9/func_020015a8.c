// addr 0x020015a8 size 0x18

typedef struct {
    char pad[0x14];
    void *field14;
    char pad18[4];
    void *field1c;
} Unk_020015a8;

void func_01ff8308(int a, void *b, void *c);

void func_020015a8(Unk_020015a8 *self) {
    func_01ff8308(1, self->field1c, self->field14);
}
