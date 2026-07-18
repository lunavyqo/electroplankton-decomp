// addr 0x02028e10 size 0x4c

typedef signed int s32;
typedef long long s64;

typedef struct {
    char pad00[0x14];
    s32 field14;
} Obj_02028e10;

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void func_02028e10(Obj_02028e10 *self) {
    self->field14 = FX_MUL(self->field14, 0xeb8);
}
