// addr 0x02001c3c size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001c3c;

void func_020487ec(int a, int b, int c);

void func_02001c3c(Unk_02001c3c *self) {
    func_020487ec(self->field08, self->field0c, self->field10);
}
