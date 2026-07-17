// addr 0x02005a20 size 0x38

extern void *data_0206f450;
extern int data_020675b0;

void func_02043100(void *p);
void func_02002910(void);

void func_02005a20(void) {
    void *p = data_0206f450;
    data_020675b0 = 0xff;
    func_02043100(p);
    func_02002910();
}
