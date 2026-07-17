// NONMATCHING: first draft of post-process mix; wrap/regalloc vs retail (div unknown)
// addr 0x0200387c size 0x19c

typedef signed short s16;

extern s16 *data_020676f0;
extern s16 *data_0206770c;
extern s16 *data_02067704;
extern s16 *data_020676f8;
extern s16 *data_02067708;
extern unsigned char data_0205d0f8;
extern s16 data_0206b3e0[];
extern s16 data_02067be0[];
extern unsigned char data_0206ebe0;

void func_0204bf64(void *src, void *dst, unsigned int n);
void func_0204af2c(void *buf, int size);
void func_020033f0(s16 *a, s16 *b, unsigned int len, int flag, s16 *p);

void func_0200387c(s16 *a, s16 *b, unsigned int len, int flag) {
    unsigned int n;
    unsigned int i;
    int gain;
    int t;
    s16 *p;
    s16 *q;

    if (flag != 0) {
        return;
    }

    n = len >> 1;

    func_0204bf64(a, data_020676f0, len);
    func_0204bf64(b, data_0206770c, len);
    func_0204af2c(data_020676f0, (int)len);
    func_0204af2c(data_0206770c, (int)len);
    func_020033f0(data_020676f0, data_0206770c, len, flag, data_02067704);

    p = (s16 *)((char *)data_0206770c + len);
    q = (s16 *)((char *)data_020676f0 + len);
    data_0206770c = p;
    data_020676f0 = q;
    if ((unsigned)((char *)q + len) > (unsigned)&data_0206ebe0) {
        data_020676f0 = data_0206b3e0;
    }
    if ((unsigned)((char *)data_0206770c + len) > (unsigned)data_0206b3e0) {
        data_0206770c = data_02067be0;
    }

    data_02067708 = data_020676f0;
    data_020676f8 = data_0206770c;

    i = 0;
    if (n != 0) {
        gain = data_0205d0f8;
        do {
            t = gain * data_02067708[i];
            a[i] = (s16)(a[i] + (t / 128));
            t = gain * data_020676f8[i];
            b[i] = (s16)(b[i] + (t / 128));
            i++;
        } while (i < n);
    }
}
