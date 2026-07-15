// addr 0x020066f4 size 0xf0
// NONMATCHING: table/idx/flag regalloc only (div=5); logic/size match

typedef struct {
    char pad[0xa7e];
    unsigned char idx;
    unsigned char pad_a7f;
    unsigned char flag;
    unsigned char state;
    unsigned char counter;
} G_020708a4;

extern volatile G_020708a4 data_020708a4;
extern unsigned char data_02070cac[];

void func_0200571c(void);

void func_020066f4(void) {
    unsigned char idx = data_020708a4.idx;
    unsigned char flag = data_020708a4.flag;
    int val = data_02070cac[idx];
    unsigned char st;

    if (flag != 0) {
        data_020708a4.state = 0;
        return;
    }

    st = data_020708a4.state;
    switch (st) {
    case 0:
        if (val >= 0x14) {
            data_020708a4.state = st + 1;
        }
        break;
    case 1:
        if (val < 3) {
            data_020708a4.state = st + 1;
            data_020708a4.counter = 0;
        }
        break;
    case 2:
        if (val >= 0x14) {
            data_020708a4.state = 1;
            return;
        }
        data_020708a4.counter = data_020708a4.counter + 1;
        if (data_020708a4.counter <= 0x21) {
            return;
        }
        func_0200571c();
        data_020708a4.state = 0;
        break;
    }
}
