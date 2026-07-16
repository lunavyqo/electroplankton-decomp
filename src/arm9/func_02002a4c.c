// addr 0x02002a4c size 0x4c

typedef struct {
    int field00;
    int field04;
    int field08;
} Unk;

extern Unk data_020675cc;
extern Unk data_020675c0;

int func_02045db0(int a, int b);

void func_02002a4c(int a) {
    int t;
    data_020675c0.field00 = 0x7f000;
    t = func_02045db0(data_020675cc.field00, a << 12);
    data_020675c0.field04 = t;
    data_020675c0.field08 = 1;
}
