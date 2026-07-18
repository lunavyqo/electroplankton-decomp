// addr 0x02001ce4 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001ce4;

void func_0204864c(int a, int b, int c);

void func_02001ce4(Unk_02001ce4 *self) {
    func_0204864c(self->field08, self->field0c, self->field10);
}
