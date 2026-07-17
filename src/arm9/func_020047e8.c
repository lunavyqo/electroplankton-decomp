// addr 0x020047e8 size 0x9c

extern unsigned char data_0206ee30;
extern unsigned char *data_0206edec;
extern void *data_020675b4;
extern unsigned char data_0206ede8;
extern int data_020675b0;

void func_02002950(void);
void func_02043118(void *p);
void func_020454f0(int a, void *b);
void func_02003c54(int a);
void func_02002d50(int a);

void func_020047e8(void) {
    func_02002950();
    data_0206edec = &data_0206ee30;
    func_02043118(data_0206edec);
    *(int *)(data_0206edec + 4) = 0;
    func_020454f0(2, data_020675b4);
    func_02003c54(0x201);
    func_02002d50(0x10);
    *(int *)(data_0206edec + 8) = 0x81df;
    data_0206ede8 = 0;
    data_020675b0 = 2;
}
