// addr 0x020430e0 size 0x10

typedef struct {
    unsigned char pad[0x40];
    unsigned char field_40;
} Unk_430e0_inner;

void func_020430e0(Unk_430e0_inner **p, unsigned char v) {
    Unk_430e0_inner *q = *p;
    if (q != 0) {
        q->field_40 = v;
    }
}
