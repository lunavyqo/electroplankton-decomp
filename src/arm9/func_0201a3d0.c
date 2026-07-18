// addr 0x0201a3d0 size 0x10

typedef struct {
    int a;
    int b;
    int c;
} Vec3i;

typedef struct {
    int pad0;
    Vec3i v;
} Unk_1a3d0;

void func_0201a3d0(Unk_1a3d0 *dst, Vec3i *src) {
    dst->v = *src;
}
