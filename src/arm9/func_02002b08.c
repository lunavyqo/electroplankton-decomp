// addr 0x02002b08 size 0x134

typedef struct {
    int field00;
    int field04;
    int field08;
} Unk12;

extern int data_020675b0;
extern Unk12 data_020675cc;
extern Unk12 data_020675c0;
extern int data_020675bc;
extern int data_020675a4;
extern int data_0206759c;

void func_02004144(void);
void func_0200447c(void);
void func_02004b68(void);
void func_02004f08(void);
void func_020056b0(void);
void func_02005fe8(void);
void func_02042294(int a);
void func_020422a0(void);

void func_02002b08(void) {
    int v = data_020675b0;
    int t;

    switch (v) {
    case 1:
        func_02004144();
        break;
    case 5:
        func_02004f08();
        break;
    case 9:
        func_02005fe8();
        break;
    case 6:
        func_020056b0();
        break;
    case 4:
        func_02004b68();
        break;
    case 2:
        func_0200447c();
        break;
    }

    if (data_020675cc.field08 != 0) {
        t = data_020675cc.field00 - data_020675cc.field04;
        data_020675cc.field00 = t;
        if (t < 0) {
            data_020675cc.field00 = 0;
        }
    }

    if (data_020675c0.field08 != 0) {
        t = data_020675c0.field00 - data_020675c0.field04;
        data_020675c0.field00 = t;
        if (t < 0) {
            data_020675c0.field00 = 0;
        }
        func_02042294(data_020675c0.field00 >> 12);
    }

    data_020675bc = 1;
    func_020422a0();
    t = data_020675a4;
    data_0206759c = 0;
    data_020675a4 = t + 1;
    if (data_020675a4 < 0) {
        data_020675a4 = 0x3c;
    }
    data_020675bc = 0;
}
