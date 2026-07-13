// addr 0x02001a64 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001a64;

void func_02048374(int a, int b, int c);

void func_02001a64(Unk_02001a64 *self) {
    func_02048374(self->field08, self->field0c, self->field10);
}
