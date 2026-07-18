// addr 0x02033924 size 0x1c

typedef struct {
    unsigned char pad[0x588];
    int field588;
} Unk_02033924;

void func_020321e8(Unk_02033924 *self, int a, int b);

void func_02033924(Unk_02033924 *self, int val) {
    self->field588 = val;
    func_020321e8(self, 1, 0xffffecc8);
}
