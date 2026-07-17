// addr 0x02004378 size 0x4c

extern int data_020675b0;
extern unsigned char *data_0206ece4;

void func_02043100(void *p);
void func_02002910(void);

void func_02004378(void) {
    int i;
    int off;
    unsigned char **base;

    data_020675b0 = 0xff;
    i = 0;
    off = 0;
    do {
        func_02043100(data_0206ece4 + off);
        i++;
        off += 4;
    } while (i < 6);
    func_02002910();
}
