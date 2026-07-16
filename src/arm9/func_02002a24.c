// addr 0x02002a24 size 0x28

typedef struct {
    int field00;
    int field04;
    int field08;
} Unk_020675c0;

extern Unk_020675c0 data_020675c0;

void func_02042294(int a);

void func_02002a24(void) {
    data_020675c0.field08 = 0;
    data_020675c0.field00 = 0x7f000;
    func_02042294(0x7f);
}
