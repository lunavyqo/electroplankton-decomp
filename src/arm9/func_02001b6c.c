// addr 0x02001b6c size 0x28

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001b6c;

void func_02048f98(void);
void func_02048e34(int a, int b, int c);
void func_02048dc4(void);

void func_02001b6c(Unk_02001b6c *self) {
    func_02048f98();
    func_02048e34(self->field08, self->field0c, self->field10);
    func_02048dc4();
}
