// addr 0x02001cc8 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001cc8;

void func_0204898c(int a, int b, int c);

void func_02001cc8(Unk_02001cc8 *self) {
    func_0204898c(self->field08, self->field0c, self->field10);
}
