// addr 0x0203ed6c size 0x3f4

typedef signed short s16;
typedef long long s64;
typedef int s32;
typedef unsigned int u32;

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800LL) >> 12))

int func_0203d898(int idx);

void func_0203ed6c(int self, int idx, int t) {
    int row;
    int obj;
    int inv;
    s32 a, b;

    row = idx * 0x18 + self;
    obj = *(int *)(self + 0x448);
    inv = 0x1000 - t;

    a = FX_MUL(*(s16 *)(obj + 0x4f4), inv);
    b = FX_MUL(*(s16 *)(row + 0x44), t);
    *(s16 *)(obj + 0x4f4) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x4f6), inv);
    b = FX_MUL(*(s16 *)(row + 0x46), t);
    *(s16 *)(obj + 0x4f6) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x4fa), inv);
    b = FX_MUL(*(s16 *)(row + 0x4a), t);
    *(s16 *)(obj + 0x4fa) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x4fc), inv);
    b = FX_MUL(*(s16 *)(row + 0x4c), t);
    *(s16 *)(obj + 0x4fc) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x500), inv);
    b = FX_MUL(*(s16 *)(row + 0x50), t);
    *(s16 *)(obj + 0x500) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x502), inv);
    b = FX_MUL(*(s16 *)(row + 0x52), t);
    *(s16 *)(obj + 0x502) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x506), inv);
    b = FX_MUL(*(s16 *)(row + 0x56), t);
    *(s16 *)(obj + 0x506) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x508), inv);
    b = FX_MUL(*(s16 *)(row + 0x58), t);
    *(s16 *)(obj + 0x508) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x50c), inv);
    b = FX_MUL(*(s16 *)(row + 0x23c), t);
    *(s16 *)(obj + 0x50c) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x50e), inv);
    b = FX_MUL(*(s16 *)(row + 0x23e), t);
    *(s16 *)(obj + 0x50e) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x512), inv);
    b = FX_MUL(*(s16 *)(row + 0x242), t);
    *(s16 *)(obj + 0x512) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x514), inv);
    b = FX_MUL(*(s16 *)(row + 0x244), t);
    *(s16 *)(obj + 0x514) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x518), inv);
    b = FX_MUL(*(s16 *)(row + 0x248), t);
    *(s16 *)(obj + 0x518) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x51a), inv);
    b = FX_MUL(*(s16 *)(row + 0x24a), t);
    *(s16 *)(obj + 0x51a) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x51e), inv);
    b = FX_MUL(*(s16 *)(row + 0x24e), t);
    *(s16 *)(obj + 0x51e) = (s16)(a + b);

    a = FX_MUL(*(s16 *)(obj + 0x520), inv);
    b = FX_MUL(*(s16 *)(row + 0x250), t);
    *(s16 *)(obj + 0x520) = (s16)(a + b);

    {
        int src_val = func_0203d898(idx);
        a = FX_MUL(*(int *)(self + 0x440), inv);
        b = FX_MUL(src_val, t);
        *(int *)(self + 0x440) = a + b;
    }
}
