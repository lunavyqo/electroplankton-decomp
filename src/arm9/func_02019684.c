// addr 0x02019684 size 0x1c

typedef struct {
    unsigned char pad[0x68];
    int field68;
    unsigned char pad2[0x10];
    int field7c;
} Unk_02019684;

void func_0204be8c(int a, int b, int c, int d);

void func_02019684(Unk_02019684 *self) {
    func_0204be8c(1, self->field68, 0, self->field7c);
}
