// addr 0x02001b44 size 0x28

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001b44;

void func_02048d7c(void);
void func_02048d08(int a, int b, int c);
void func_02048cb0(void);

void func_02001b44(Unk_02001b44 *self) {
    func_02048d7c();
    func_02048d08(self->field08, self->field0c, self->field10);
    func_02048cb0();
}
