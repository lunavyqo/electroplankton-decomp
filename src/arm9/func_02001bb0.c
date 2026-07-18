// addr 0x02001bb0 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001bb0;

void func_02048a54(int a, int b, int c);

void func_02001bb0(Unk_02001bb0 *self) {
    func_02048a54(self->field08, self->field0c, self->field10);
}
