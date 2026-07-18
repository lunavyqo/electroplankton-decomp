// addr 0x02001c90 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001c90;

void func_020488bc(int a, int b, int c);

void func_02001c90(Unk_02001c90 *self) {
    func_020488bc(self->field08, self->field0c, self->field10);
}
