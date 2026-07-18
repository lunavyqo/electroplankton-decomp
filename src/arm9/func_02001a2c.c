// addr 0x02001a2c size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001a2c;

void func_020486b4(int a, int b, int c);

void func_02001a2c(Unk_02001a2c *self) {
    func_020486b4(self->field08, self->field0c, self->field10);
}
