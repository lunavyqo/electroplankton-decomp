// addr 0x02001a10 size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001a10;

void func_02048bec(int a, int b, int c);

void func_02001a10(Unk_02001a10 *self) {
    func_02048bec(self->field08, self->field0c, self->field10);
}
