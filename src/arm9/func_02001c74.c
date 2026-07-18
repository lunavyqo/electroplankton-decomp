// addr 0x02001c74 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001c74;

void func_020484ac(int a, int b, int c);

void func_02001c74(Unk_02001c74 *self) {
    func_020484ac(self->field08, self->field0c, self->field10);
}
