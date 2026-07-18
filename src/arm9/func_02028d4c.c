// addr 0x02028d4c size 0xc4

typedef signed int s32;
typedef long long s64;

typedef struct {
    char pad00[4];
    s32 field04;
    s32 field08;
    char pad0c[0x28];
    s32 field34;
    s32 field38;
} Obj_02028d4c;

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void func_02028d4c(Obj_02028d4c *self) {
    self->field04 = FX_MUL(self->field04, 0xe66) + FX_MUL(self->field34, 0x19a);
    self->field08 = FX_MUL(self->field08, 0xe66) + FX_MUL(self->field38, 0x19a);
}
