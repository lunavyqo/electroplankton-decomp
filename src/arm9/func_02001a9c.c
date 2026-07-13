// addr 0x02001a9c size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001a9c;

void func_02048784(int a, int b, int c);

void func_02001a9c(Unk_02001a9c *self) {
    func_02048784(self->field08, self->field0c, self->field10);
}
