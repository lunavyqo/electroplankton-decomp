// addr 0x02009554 size 0x10

typedef struct {
    unsigned char pad[0x1c];
    int field_1c;
} Unk_0208938c;

extern Unk_0208938c data_0208938c;

void func_02009554(int v) {
    data_0208938c.field_1c = v;
}
