// addr 0x02002a98 size 0x1c

typedef struct {
    int field00;
    int field04;
    int field08;
} Unk_020675cc;

extern Unk_020675cc data_020675cc;

void func_02002a98(void) {
    data_020675cc.field08 = 0;
    data_020675cc.field00 = 0x100000;
}
