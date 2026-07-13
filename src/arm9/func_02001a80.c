// addr 0x02001a80 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001a80;

void func_02048784(int a, int b, int c);

void func_02001a80(Unk_02001a80 *self) {
    func_02048784(self->field08, self->field0c, self->field10);
}
