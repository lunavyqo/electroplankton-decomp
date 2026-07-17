// addr 0x02003c98 size 0xd0

extern unsigned int data_0206b3e0[];
extern unsigned int data_02067be0[];
extern unsigned short data_02067720[];
extern void *data_020676f0;
extern void *data_0206770c;
extern unsigned char data_020677e0[];

void func_0204bf50(unsigned int val, void *dst, unsigned int size);
void func_0204bf1c(unsigned short val, void *dst, unsigned int size);
void func_0204af2c(void *buf, int size);
void func_02043fbc(void *a, int b, int c, int d, int e, void *f, int g);
void func_02003a18(void);

void func_02003c98(void) {
    volatile unsigned int z0;
    volatile unsigned int z1;
    volatile unsigned short zs;

    z0 = 0;
    func_0204bf50(z0, data_0206b3e0, 0x3800);
    z1 = 0;
    func_0204bf50(z1, data_02067be0, 0x3800);
    zs = 0;
    func_0204bf1c(zs, data_02067720, 0xc0);
    func_0204af2c(data_0206b3e0, 0x3800);
    func_0204af2c(data_02067be0, 0x3800);
    data_020676f0 = data_0206b3e0;
    data_0206770c = data_02067be0;
    func_02043fbc(data_020677e0, 0x400, 0, 0x7d00, 2, func_02003a18, 0);
}
