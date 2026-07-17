// addr 0x020043c4 size 0xb8

extern unsigned char data_0206ece8;
extern unsigned char *data_0206ece4;
extern void *data_020675b4;
extern int data_020675b0;

void func_02002950(void);
void func_02043118(void *p);
void func_020041ac(int a);
void func_020454f0(int a, void *b);
void func_02003c54(int a);
void func_02002d50(int a);
void func_02002d30(unsigned int a);

void func_020043c4(void) {
    unsigned char **pp;
    int i;
    int off;
    int n;

    func_02002950();
    i = 0;
    off = 0;
    data_0206ece4 = &data_0206ece8;
    n = -1;
    pp = &data_0206ece4;
    do {
        func_02043118(*pp + off);
        func_020041ac(i);
        off += 4;
        ((int *)(*pp + 0x60))[i] = n;
        *(unsigned char *)(*pp + i + 0x78) = (unsigned char)i;
        i++;
    } while (i < 6);
    func_020454f0(1, data_020675b4);
    func_02003c54(0x301);
    func_02002d50(0x28);
    func_02002d30(0x84d0);
    data_020675b0 = 1;
}
