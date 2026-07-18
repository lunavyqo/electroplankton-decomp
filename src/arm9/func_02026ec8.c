// addr 0x02026ec8 size 0x10

typedef struct {
    int a;
    int b;
    int c;
} Vec3i;

typedef struct {
    int pad0;
    Vec3i v;
} Unk_26ec8;

void func_02026ec8(Unk_26ec8 *dst, Vec3i *src) {
    dst->v = *src;
}
