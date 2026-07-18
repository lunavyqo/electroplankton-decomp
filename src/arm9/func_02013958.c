// addr 0x02013958 size 0x4f0
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef long long s64;
#define FX_MUL(a, b) ((s32)(((s64)(a) * (s32)(b) + 0x800LL) >> 12))
typedef struct { int angle; int pad[2]; } AngSlot;
typedef struct { void *obj; int pad[2]; } ObjSlot;
typedef struct { int v; int pad; } Pair8;
extern AngSlot data_0208f30c[];
extern ObjSlot data_0208f308[];
extern s16 data_0205872c[];
extern Pair8 data_0205e624[];
extern Pair8 data_0205e628[];
int func_020144f4(int type);
void func_02026ec8(void *obj, int *vec);
void func_02027028(void *obj);
void func_0202f8e8(void *obj, int *vec);
void func_0202f930(void *obj);
void func_0201df1c(void *obj, int *vec);
void func_0201e01c(void *obj);
void func_0202b590(void *obj, int vx, int vy);
void func_0202b654(void *obj);
void func_0201a3d0(void *obj, int *vec);
void func_0201a3e0(void *obj);
void func_0201507c(void *obj, int *vec);
void func_0201505c(void *obj);
void func_0203598c(void *obj, int *vec);
void func_0203599c(void *obj);
void func_02022d3c(void *obj, int *vec);
void func_02022d4c(void *obj);
void func_02039794(void *obj, int vx, int vy);
void func_020397c0(void *obj);
void func_0203d3d0(void *obj, int vx, int vy);
void func_0203d468(void *obj);
void func_0204b7d4(void);

void func_02013958(int x, int type) {
    s32 y;
    s32 angle;
    s32 fx;
    s32 idx;
    s32 sinv;
    int vec[3];
    int *angp;

    if (func_020144f4(type) == 0) {
        return;
    }

    data_0208f30c[type].angle += 0x3000;
    data_0208f30c[type].angle %= 0x168000;
    angp = &data_0208f30c[type].angle;

    if ((u32)(type - 7) <= 1U) {
        y = 0x333;
    } else {
        angle = *angp;
        if (angle < 0) {
            fx = FX_MUL(angle - 0x800, 0xb60b6);
            idx = (s32)(((u32)fx << 4) >> 16);
        } else {
            fx = FX_MUL(angle + 0x800, 0xb60b6);
            idx = (s32)(((u32)fx << 4) >> 16);
        }
        sinv = (s32)*(s16 *)((char *)data_0205872c + (idx >> 4) * 4);
        y = FX_MUL(sinv, 0x19a) + 0x333;
    }

    switch (type) {
    case 0:
        vec[2] = (int)0xffffe19a;
        vec[0] = x + data_0205e624[type].v;
        vec[1] = y + data_0205e628[type].v;
        func_02026ec8(data_0208f308[type].obj, vec);
        func_02027028(data_0208f308[type].obj);
        return;
    case 2:
        vec[2] = (int)0xffffe19a;
        vec[0] = x + data_0205e624[type].v;
        vec[1] = y + data_0205e628[type].v;
        func_0201df1c(data_0208f308[type].obj, vec);
        func_0201e01c(data_0208f308[type].obj);
        return;
    case 5:
        vec[2] = (int)0xffffe19a;
        vec[0] = x + data_0205e624[type].v;
        vec[1] = y + data_0205e628[type].v;
        func_0201507c(data_0208f308[type].obj, vec);
        func_0201505c(data_0208f308[type].obj);
        return;
    case 7:
        vec[2] = (int)0xffffe19a;
        vec[0] = x + data_0205e624[type].v;
        vec[1] = y + data_0205e628[type].v;
        func_02022d3c(data_0208f308[type].obj, vec);
        func_02022d4c(data_0208f308[type].obj);
        return;
    case 3: {
        int z = (int)0xffffe19a;
        int tx = data_0205e624[type].v;
        int ty = data_0205e628[type].v;
        vec[2] = z;
        vec[0] = x + tx;
        vec[1] = y + ty;
        func_0202b590(data_0208f308[type].obj, vec[0], vec[1]);
        func_0202b654(data_0208f308[type].obj);
        return;
    }
    case 4:
        vec[2] = (int)0xffffe19a;
        vec[0] = x + data_0205e624[type].v;
        vec[1] = y + data_0205e628[type].v;
        func_0201a3d0(data_0208f308[type].obj, vec);
        func_0201a3e0(data_0208f308[type].obj);
        return;
    case 1:
        vec[2] = (int)0xffffe19a;
        vec[0] = x + data_0205e624[type].v;
        vec[1] = y + data_0205e628[type].v;
        func_0202f8e8(data_0208f308[type].obj, vec);
        func_0202f930(data_0208f308[type].obj);
        return;
    case 6:
        vec[2] = (int)0xffffe19a;
        vec[0] = x + data_0205e624[type].v;
        vec[1] = y + data_0205e628[type].v;
        func_0203598c(data_0208f308[type].obj, vec);
        func_0203599c(data_0208f308[type].obj);
        return;
    case 8: {
        int z = (int)0xffffe19a;
        int tx = data_0205e624[type].v;
        int ty = data_0205e628[type].v;
        vec[2] = z;
        vec[0] = x + tx;
        vec[1] = y + ty;
        func_02039794(data_0208f308[type].obj, vec[0], vec[1]);
        func_020397c0(data_0208f308[type].obj);
        return;
    }
    case 9: {
        int z = (int)0xffffe19a;
        int tx = data_0205e624[type].v;
        int ty = data_0205e628[type].v;
        vec[2] = z;
        vec[0] = x + tx;
        vec[1] = y + ty;
        func_0203d3d0(data_0208f308[type].obj, vec[0], vec[1]);
        func_0203d468(data_0208f308[type].obj);
        return;
    }
    default:
        func_0204b7d4();
        return;
    }
}
