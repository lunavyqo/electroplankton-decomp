// addr 0x020019f4 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_020019f4;

void func_020489f4(int a, int b, int c);

void func_020019f4(Unk_020019f4 *self) {
    func_020489f4(self->field08, self->field0c, self->field10);
}
