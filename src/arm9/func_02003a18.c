// addr 0x02003a18 size 0x22c

typedef signed short s16;

extern int data_020676fc;
extern s16 data_02067714[];
extern s16 data_0205d0fc;
extern unsigned int data_0205d104;
extern int data_02067710;

void func_0200347c(s16 *a, s16 *b, unsigned int len, int flag, s16 *p);
void func_020033f0(s16 *a, s16 *b, unsigned int len, int flag, s16 *p);
void func_0200336c(s16 *a, s16 *b, unsigned int len, int flag, s16 *p);
void func_020032e0(s16 *a, s16 *b, unsigned int len, int flag, s16 *p);
void func_0200387c(s16 *a, s16 *b, unsigned int len, int flag, int zero);
void func_020036ec(s16 *a, s16 *b, unsigned int len, int flag, int zero);
void func_02003500(s16 *a, s16 *b, unsigned int len, int flag, int zero);
void func_02003170(s16 *a, s16 *b, unsigned int len, int flag, s16 *p);
void func_0200320c(s16 *a, s16 *b, unsigned int len, int flag, unsigned int *p);
void func_02002f8c(s16 *a, s16 *b, unsigned int len, int flag, s16 *p);
void func_02002d70(s16 *a, s16 *b, unsigned int len, int flag, s16 *p);
void func_0204af2c(void *buf, int size);

void func_02003a18(s16 *a, s16 *b, unsigned int len, int flag) {
    int f;

    if ((data_020676fc & 8) != 0) {
        func_0200347c(a, b, len, flag, data_02067714);
    }
    if ((data_020676fc & 0x10) != 0) {
        func_020033f0(a, b, len, flag, data_02067714);
    }
    if ((data_020676fc & 0x20) != 0) {
        func_0200336c(a, b, len, flag, data_02067714);
    }
    if ((data_020676fc & 0x40) != 0) {
        func_020032e0(a, b, len, flag, data_02067714);
    }

    f = data_020676fc;
    if ((f & 1) != 0) {
        func_0200387c(a, b, len, flag, 0);
    } else if ((f & 2) != 0) {
        func_020036ec(a, b, len, flag, 0);
    } else if ((f & 4) != 0) {
        func_02003500(a, b, len, flag, 0);
    }

    if ((data_020676fc & 0x80) != 0) {
        func_02003170(a, b, len, flag, &data_0205d0fc);
    }

    if ((data_020676fc & 0x100) == 0) {
        data_0205d104 = 0x10000;
    } else {
        func_0200320c(a, b, len, flag, &data_0205d104);
    }

    switch (data_02067710) {
    case 0:
        func_02002f8c(a, b, len, flag, data_02067714);
        break;
    case 1:
        func_02002d70(a, b, len, flag, data_02067714);
        break;
    case 2:
        break;
    }

    func_0204af2c(a, (int)len);
    func_0204af2c(b, (int)len);
}
