// addr 0x02005918 size 0x7c

extern char data_0206f350;
extern void *data_0206f344;
extern void *data_020675b4;
extern int data_0206f34c;
extern int data_020675b0;

void func_02002950(void);
void func_02043118(void *p);
void func_0200565c(void);
void func_020454f0(int a, void *p);
void func_02003c54(int a);
void func_02002d50(int a);

void func_02005918(void) {
    func_02002950();
    data_0206f344 = &data_0206f350;
    func_02043118(&data_0206f350);
    func_0200565c();
    data_0206f34c = 0;
    func_020454f0(6, data_020675b4);
    func_02003c54(0x301);
    func_02002d50(0x1c);
    data_020675b0 = 6;
}
