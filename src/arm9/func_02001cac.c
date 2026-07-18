// addr 0x02001cac size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001cac;

void func_0204857c(int a, int b, int c);

void func_02001cac(Unk_02001cac *self) {
    func_0204857c(self->field08, self->field0c, self->field10);
}
