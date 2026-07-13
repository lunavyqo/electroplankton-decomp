// addr 0x02001ab8 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001ab8;

void func_02048444(int a, int b, int c);

void func_02001ab8(Unk_02001ab8 *self) {
    func_02048444(self->field08, self->field0c, self->field10);
}
