// addr 0x02001ad4 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001ad4;

void func_02048854(int a, int b, int c);

void func_02001ad4(Unk_02001ad4 *self) {
    func_02048854(self->field08, self->field0c, self->field10);
}
