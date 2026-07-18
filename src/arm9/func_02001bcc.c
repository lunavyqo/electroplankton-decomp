// addr 0x02001bcc size 0x1c

typedef struct {
    int unk00;
    int unk04;
    int field08;
    int field0c;
    int field10;
} Unk_02001bcc;

void func_02048c54(int a, int b, int c);

void func_02001bcc(Unk_02001bcc *self) {
    func_02048c54(self->field08, self->field0c, self->field10);
}
