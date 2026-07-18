// addr 0x02001c58 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001c58;

void func_020487ec(int a, int b, int c);

void func_02001c58(Unk_02001c58 *self) {
    func_020487ec(self->field08, self->field0c, self->field10);
}
