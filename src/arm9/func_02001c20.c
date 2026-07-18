// addr 0x02001c20 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001c20;

void func_020483dc(int a, int b, int c);

void func_02001c20(Unk_02001c20 *self) {
    func_020483dc(self->field08, self->field0c, self->field10);
}
