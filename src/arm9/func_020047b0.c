// addr 0x020047b0 size 0x38

extern void *data_0206edec;
extern int data_020675b0;

void func_02043100(void *p);
void func_02002910(void);

void func_020047b0(void) {
    void *p = data_0206edec;
    data_020675b0 = 0xff;
    func_02043100(p);
    func_02002910();
}
