// addr 0x020058e0 size 0x38

extern void *data_0206f344;
extern int data_020675b0;

void func_02043100(void *p);
void func_02002910(void);

void func_020058e0(void) {
    void *p = data_0206f344;
    func_02043100(p);
    func_02002910();
    data_020675b0 = 0xff;
}
