// addr 0x02028f68 size 0xe8

typedef signed int s32;
typedef long long s64;

typedef struct {
    char pad00[8];
    s32 field08;
    s32 field0c;
    char pad10[0x958];
    s32 field968;
    char pad96c[0x20];
    s32 field98c;
    s32 field990;
    char pad994[0x14];
    s32 field9a8;
} Obj_02028f68;

#define FX_SQUARE(v) ((s32)(((s64)(v) * (v) + 0x800) >> 12))

int func_02028f68(Obj_02028f68 *self, int x, int y) {
    s32 v98c, v08, v990, v0c;
    s32 bx, by, dx, dy, dist;
    Obj_02028f68 *p;

    if (self->field9a8 != 0) {
        v98c = self->field98c;
        v08 = self->field08;
        v990 = self->field990;
        v0c = self->field0c;
        bx = v98c + v08;
        by = v990 + v0c;
        dy = y - by;
        dx = x - bx;
        dist = FX_SQUARE(dx) + FX_SQUARE(dy);
        if (dist < 0x18a) {
            return 1;
        }

        p = (Obj_02028f68 *)((char *)self + (self->field968 - 1) * 0x20);
        by = v990 + p->field0c;
        dy = y - by;
        bx = v98c + p->field08;
        dx = x - bx;
        dist = FX_SQUARE(dx) + FX_SQUARE(dy);
        if (dist < 0x18a) {
            return 1;
        }
    }
    return 0;
}
