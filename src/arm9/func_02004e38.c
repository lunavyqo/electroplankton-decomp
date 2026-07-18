// addr 0x02004e38 size 0x48

extern unsigned char *data_0206f038;
extern int data_020675b0;

void func_02043100(void *p);
void func_02002910(void);

void func_02004e38(void) {
    void *p = data_0206f038;
    data_020675b0 = 0xff;
    func_02043100(p);
    func_02043100((char *)data_0206f038 + 4);
    func_02002910();
}
