// addr 0x020430f0 size 0x10

typedef struct {
    unsigned char pad[0x41];
    unsigned char field_41;
} Unk_430f0_inner;

void func_020430f0(Unk_430f0_inner **p, unsigned char v) {
    Unk_430f0_inner *q = *p;
    if (q != 0) {
        q->field_41 = v;
    }
}
