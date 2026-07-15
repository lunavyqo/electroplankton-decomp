// addr 0x02006a10 size 0x380
// NONMATCHING: pure-C partial reconstruction (div=224)

typedef struct {
    char pad[0xa7e];
    unsigned char idx;       /* +0xa7e */
    unsigned char field_a7f;
    unsigned char pad_a80;
    unsigned char pad_a81;
    unsigned char pad_a82;
    unsigned char field_a83;
} G_020708a4;

extern G_020708a4 data_020708a4;
extern unsigned char data_0206ffac[]; /* base + a7f<<8 */
extern unsigned char data_02070cac[]; /* ring of values */
extern unsigned char data_0206f8a4[]; /* history buffers */
extern unsigned char data_02070dac[];

int func_020076f4(int a, void *b, int c, int d, int e);
int func_020091a4(int a, int b, int c, int d, int e);
void func_02009290(void *a, int b, int c, int d);

void func_02006a10(void) {
    int raw;
    int level;
    int clamped;
    int out = 0;
    int maxv;
    int count;
    int i;
    int idx;
    int thr;
    unsigned char v;

    raw = func_020076f4(0x80, data_0206ffac + (data_020708a4.field_a7f << 8), 0x7d0, 0, 0x3e8);
    /* (raw + (raw>>3)>>28) >> 4  — arithmetic rounding for asr */
    level = raw >> 3;
    level = (raw + ((unsigned)level >> 28)) >> 4;

    if (level > 0xff) {
        clamped = 0xff;
    } else {
        clamped = level;
    }
    data_02070cac[data_020708a4.idx] = (unsigned char)clamped;

    if (level < 0x23) {
        idx = data_020708a4.idx;
        maxv = 0;
        count = 0;
        for (;;) {
            idx = idx - 1;
            if (idx < 0) {
                idx += 0x100;
            }
            /* load from data_0206f8a4 + idx + 0x1000 + 0x408 */
            v = data_0206f8a4[idx + 0x1408];
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

    /* second phase — scan history for nonzero, build work buffer, call helpers */
    {
        int j;
        int k;
        unsigned char buf[0x50];
        idx = data_020708a4.idx;
        j = 0;
        k = 0;
        for (i = 0; i < 0x1f; i++) {
            idx = idx - 1;
            if (idx < 0) {
                idx += 0x100;
            }
            v = data_0206f8a4[idx + 0x1508];
            if (v == 0) {
                break;
            }
            /* continue scan — simplified body for draft */
            j = j + 1;
        }
        (void)buf;
        (void)k;
        (void)j;
    }
}
