// addr 0x02002ab4 size 0x54

typedef struct {
    int field00;
    int field04;
    int field08;
} Unk;

extern Unk data_020675cc;

int func_02045db0(int a, int b);

void func_02002ab4(int a) {
    int t;
    if (data_020675cc.field08 != 0) {
        return;
    }
    data_020675cc.field00 = 0x100000;
    t = func_02045db0(0x100000, a << 12);
    data_020675cc.field04 = t;
    data_020675cc.field08 = 1;
}
