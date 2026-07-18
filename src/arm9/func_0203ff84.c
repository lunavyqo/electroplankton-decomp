// addr 0x0203ff84 size 0x1c

typedef struct {
    unsigned char pad[0x6c];
    int field6c;
    unsigned char pad2[0x10];
    int field80;
} Unk_0203ff84;

void func_0204be8c(int a, int b, int c, int d);

void func_0203ff84(Unk_0203ff84 *self) {
    func_0204be8c(1, self->field6c, 0, self->field80);
}
