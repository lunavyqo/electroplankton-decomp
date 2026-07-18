// addr 0x02001b94 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001b94;

void func_02048b84(int a, int b, int c);

void func_02001b94(Unk_02001b94 *self) {
    func_02048b84(self->field08, self->field0c, self->field10);
}
