// addr 0x02001af0 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001af0;

void func_02048514(int a, int b, int c);

void func_02001af0(Unk_02001af0 *self) {
    func_02048514(self->field08, self->field0c, self->field10);
}
