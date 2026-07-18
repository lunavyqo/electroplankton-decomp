// addr 0x02001be8 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001be8;

void func_0204871c(int a, int b, int c);

void func_02001be8(Unk_02001be8 *self) {
    func_0204871c(self->field08, self->field0c, self->field10);
}
