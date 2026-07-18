// addr 0x02031910 size 0x18

typedef struct {
    int a;
    int b;
} Pair_02031910;

void func_02031910(Pair_02031910 *out, unsigned char *base, int idx) {
    *out = *(Pair_02031910 *)(base + idx * 8 + 0xb4);
}
