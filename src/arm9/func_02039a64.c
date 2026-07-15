// addr 0x02039a64 size 0x30

extern unsigned short data_0206481e[];
extern unsigned short data_0206481c[];

void func_02039a64(void *self, int flag) {
    unsigned short *src;
    int *dst = (int *)self;
    if (flag != 0) {
        src = data_0206481e;
    } else {
        src = data_0206481c;
    }
    dst[0x1b8 / 4] = src[0];
    dst[0x1bc / 4] = src[2];  // +4 bytes = +2 halfwords
    dst[0x1c0 / 4] = src[4];  // +8 bytes
}
