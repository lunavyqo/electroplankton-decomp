// addr 0x02009584 size 0x18 — copy 4 words from data_0205d364 via ldm/stm

typedef struct {
    int a;
    int b;
    int c;
    int d;
} Vec4i;

extern Vec4i data_0205d364;

void func_02009584(Vec4i *dst) {
    *dst = data_0205d364;
}
