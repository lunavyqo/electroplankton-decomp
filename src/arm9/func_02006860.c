// addr 0x02006860 size 0x1b0
// NONMATCHING: epilogue regalloc only (div=4): body byte-identical

typedef struct {
    char pad[0xa7e];
    unsigned char idx;
    char pad_a7f[5];
    unsigned char mode;
    unsigned char field_a85;
    unsigned char field_a86;
    unsigned char field_a87;
    unsigned char field_a88;
} G_020708a4;

typedef struct {
    char pad[0x50];
    unsigned short field50;
    unsigned short field52;
} G_020712a4;

extern G_020708a4 data_020708a4;
extern unsigned char data_02070cac[];
extern G_020712a4 data_020712a4;
extern unsigned char data_020712f8[];

int func_020091a4(int a, int b, int c, int d, int e);

void func_02006860(void) {
    int val;
    unsigned char mode;
    int out = 0;
    unsigned short h;
    int q;

    val = (int)data_02070cac[data_020708a4.idx];
    mode = data_020708a4.mode;

    switch (mode) {
    case 0:
        if (val >= 0x8c) {
            data_020708a4.field_a87 = 1;
            data_020708a4.mode = 1;
            data_020712a4.field50 = 1;
            data_020708a4.field_a85 = (unsigned char)val;
        }
        break;
    case 1:
        if (val < 0x1e) {
            data_020708a4.field_a86 = data_020708a4.field_a85;
            h = data_020712a4.field50;
            data_020712a4.field52 = h;
            if (h >= 0x3c) {
                q = (int)h / 60;
                out = 0x16;
                if (q >= 2) {
                    out = 0x17;
                }
                if (q >= 5) {
                    out = 0x18;
                }
                if (q >= 0xa) {
                    out = 0x19;
                }
            } else {
                if (h >= 5) {
                    data_020708a4.mode = 2;
                    data_020708a4.field_a88 = (unsigned char)out;
                } else {
                    data_020708a4.mode = (unsigned char)out;
                }
            }
        } else {
            if (val > (int)data_020708a4.field_a85) {
                data_020708a4.field_a85 = (unsigned char)val;
            }
            data_020712a4.field50 = (unsigned short)(data_020712a4.field50 + 1);
        }
        break;
    case 2:
        data_020708a4.field_a88 = (unsigned char)(data_020708a4.field_a88 + 1);
        if (data_020708a4.field_a88 > 0x1e) {
            if (data_020708a4.field_a87 <= 4) {
                out = data_020708a4.field_a87 + 0x11;
            }
            data_020708a4.mode = 0;
        } else {
            if (val >= 0x8c) {
                data_020708a4.field_a87 = (unsigned char)(data_020708a4.field_a87 + 1);
                data_020712a4.field50 = 1;
                data_020708a4.mode = 1;
            }
        }
        break;
    }

    if (out <= 0) {
        return;
    }
    {
        int r = func_020091a4((int)data_020708a4.field_a85, 0x8c, 0xff, 1, 0x10);
        data_020712f8[out] = (unsigned char)r;
        data_020708a4.mode = 0;
    }
}
