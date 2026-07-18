// addr 0x020019d8 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_020019d8;

void func_02048b1c(int a, int b, int c);

void func_020019d8(Unk_020019d8 *self) {
    func_02048b1c(self->field08, self->field0c, self->field10);
}
