// addr 0x02006a10 size 0x380
// NONMATCHING: pure C reconstruction

typedef struct {
    char pad[0xa55];
    unsigned char field_a55;
    char pad_a56[0x28];
    unsigned char idx;
    unsigned char field_a7f;
    char pad_a80[3];
    unsigned char field_a83;
} G_020708a4;

extern G_020708a4 data_020708a4;
extern unsigned char data_0206ffac[];
extern unsigned char data_02070cac[];
extern unsigned char data_0206f8a4[];
extern unsigned char data_02070dac[];
extern unsigned char data_020712f8[];
extern int data_0205d2d4[];

int func_020076f4(int a, void *b, int c, int d, int e);
int func_020091a4(int a, int b, int c, int d, int e);
int func_02009290(int a, int b, int c);

void func_02006a10(void) {
    int raw;
    int level;
    int out;
    int maxv;
    int count;
    int idx;
    int thr;
    int v;
    int r1;
    int r4;
    int r5;
    int r0h;
    int r7;
    int sl;
    int r4max;
    int r5min;
    int vals[0x13];
    int r6;
    int sb;

    raw = func_020076f4(
        0x80,
        data_0206ffac + (data_020708a4.field_a7f << 8),
        0x7d0,
        0,
        0x3e8
    );
    {
        int t = raw >> 3;
        level = (raw + ((unsigned int)t >> 28)) >> 4;
    }

    out = 0;
    {
        int clamped;
        if (level > 0xff) {
            clamped = 0xff;
        } else {
            clamped = level;
        }
        data_02070cac[data_020708a4.idx] = (unsigned char)clamped;
    }

    if (level < 0x23) {
        idx = data_020708a4.idx;
        maxv = 0;
        count = 0;
        for (;;) {
            idx = idx - 1;
            if (idx < 0) {
                idx += 0x100;
            }
            {
                unsigned char *q = data_0206f8a4 + idx;
                q = q + 0x1000;
                v = q[0x408];
            }
            if (v < 0x23) {
                break;
            }
            count = count + 1;
            if (v > maxv) {
                maxv = v;
            }
            if (count > 5) {
                break;
            }
        }
        thr = (data_020708a4.field_a83 != 0) ? 0x2d : 0x3c;
        if (data_020708a4.field_a83 != 0) {
            data_020708a4.field_a83 = data_020708a4.field_a83 - 1;
        }
        if (count <= 5) {
            if (maxv >= thr) {
                data_020708a4.field_a83 = 0x15;
                out = maxv;
            }
        }
    }

    data_02070dac[data_020708a4.idx] = (unsigned char)out;
    if (out != 0) {
        return;
    }

    r1 = data_020708a4.idx;
    r5 = 1;
    r4 = 0;
    do {
        r1 = r1 - 1;
        if (r1 < 0) {
            r1 += 0x100;
        }
        if (r4 >= 0x1f) {
            {
                unsigned char *q = data_0206f8a4 + r1;
                q = q + 0x1000;
                v = q[0x508];
            }
            if (v == 0) {
                r5 = 0;
            }
        } else {
            {
                unsigned char *q = data_0206f8a4 + r1;
                q = q + 0x1000;
                v = q[0x508];
            }
            if (v != 0) {
                r5 = 0;
                break;
            }
        }
        r4 = r4 + 1;
    } while (r4 <= 0x1f);

    if (r5 == 0) {
        return;
    }

    sl = 0;
    r4max = 0;
    r5min = 0x3e8;
    r7 = 1;
    r0h = 0;
    r1 = data_020708a4.idx;
    while (r7 <= 0x14) {
        sl = sl + 1;
        if (sl > 0x1e) {
            break;
        }
        r1 = r1 - 1;
        if (r1 < 0) {
            r1 += 0x100;
        }
        {
            unsigned char *q = data_0206f8a4 + r1;
            q = q + 0x1000;
            v = q[0x508];
        }
        if (v > 0) {
            if (sl < r5min) {
                r5min = sl;
            }
            if (sl > r4max) {
                r4max = sl;
            }
            vals[r7 - 1] = sl;
            if (v > r0h) {
                r0h = v;
            }
            r7 = r7 + 1;
            sl = 0;
        }
    }

    r6 = func_020091a4(r0h, 0x3c, 0x64, 1, 0x10);

    if (r7 >= 3 && (r4max - r5min + 1) > 5) {
        sb = (r7 >= 6) ? 5 : (r7 - 2);
        while (sb >= 0) {
            {
                int *ip = data_0205d2d4 + sb * 5;
                int lr = 1;
                int r8i = 0;
                while (r8i <= 4) {
                    int r3 = ip[4 - r8i];
                    if (r3 == 0) {
                        if (r7 != r8i + 1) {
                            lr = 0;
                        }
                        break;
                    }
                    {
                        int slv = vals[r8i];
                        int tmp = (slv > 0x14) ? 1 : 0;
                        tmp = tmp + 1;
                        if (tmp != r3) {
                            lr = 0;
                            break;
                        }
                    }
                    r8i = r8i + 1;
                }
                if (lr != 0) {
                    data_020712f8[sb + 0xc] = (unsigned char)r6;
                    return;
                }
            }
            sb = sb - 1;
        }
    }

    if (r7 >= 2 && (r4max - r5min + 1) <= 5) {
        r4 = 0;
        if (r4max <= 0xf) {
            if (func_02009290(r7, 2, 5) != 0) {
                r4 = r7 + 5;
            }
            if (r7 == 0x14) {
                r4 = 0xb;
            }
        } else {
            if (func_02009290(r7, 2, 5) != 0) {
                r4 = r7;
            }
            if (r7 == 0xa) {
                r4 = 6;
            }
        }
        if (r4 != 0) {
            data_020712f8[r4] = (unsigned char)r6;
        }
        return;
    }

    if (r7 == 1) {
        data_020708a4.field_a55 = (unsigned char)r6;
    }
}
