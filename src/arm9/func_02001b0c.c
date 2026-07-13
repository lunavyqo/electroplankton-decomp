// addr 0x02001b0c size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001b0c;

void func_02048924(int a, int b, int c);

void func_02001b0c(Unk_02001b0c *self) {
    func_02048924(self->field08, self->field0c, self->field10);
}
