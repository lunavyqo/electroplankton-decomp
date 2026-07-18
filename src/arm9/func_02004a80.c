// addr 0x02004a80 size 0x4c

extern int data_020675b0;
extern unsigned char *data_0206ef30;

void func_02043100(void *p);
void func_02002910(void);

void func_02004a80(void) {
    int i;
    int off;
    unsigned char **base;

    data_020675b0 = 0xff;
    i = 0;
    off = 0;
    do {
        func_02043100(data_0206ef30 + off);
        i++;
        off += 4;
    } while (i < 4);
    func_02002910();
}
