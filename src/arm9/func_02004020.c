// addr 0x02004020 size 0x48

extern void *data_0206ebe0;
extern int data_020675b0;

void func_02043100(void *p);
void func_02002910(void);

void func_02004020(void) {
    data_020675b0 = 0xff;
    func_02043100(data_0206ebe0);
    func_02043100((char *)data_0206ebe0 + 4);
    func_02002910();
}
