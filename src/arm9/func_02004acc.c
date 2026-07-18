// addr 0x02004acc size 0x9c

extern unsigned char data_0206ef34;
extern unsigned char *data_0206ef30;
extern void *data_020675b4;
extern int data_020675b0;

void func_02002950(void);
void func_02043118(void *p);
void func_020454f0(int a, void *b);
void func_02003c54(int a);
void func_02002d50(int a);

void func_02004acc(void) {
    int i;
    int off;
    unsigned char **pp;

    func_02002950();
    i = 0;
    off = 0;
    data_0206ef30 = &data_0206ef34;
    pp = &data_0206ef30;
    do {
        func_02043118(*pp + off);
        i++;
        off += 4;
    } while (i < 4);
    func_02043118(data_0206ef30 + 0x10);
    *(int *)(data_0206ef30 + 0x14) = 0;
    func_020454f0(3, data_020675b4);
    func_02003c54(0x104);
    func_02002d50(0x1e);
    data_020675b0 = 3;
}
