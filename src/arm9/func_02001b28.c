// addr 0x02001b28 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001b28;

void func_020485e4(int a, int b, int c);

void func_02001b28(Unk_02001b28 *self) {
    func_020485e4(self->field08, self->field0c, self->field10);
}
