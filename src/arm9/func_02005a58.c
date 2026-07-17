// addr 0x02005a58 size 0x74

typedef struct {
    int field00;
    int field04;
} Obj;

extern Obj data_0206f454;
extern Obj *data_0206f450;
extern void *data_020675b4;
extern int data_020675b0;

void func_02002950(void);
void func_02043118(void *p);
void func_020454f0(int a, void *p);
void func_02003c54(int a);
void func_02002d50(int a);

void func_02005a58(void) {
    func_02002950();
    data_0206f450 = &data_0206f454;
    func_02043118(&data_0206f454);
    data_0206f450->field04 = 0;
    func_020454f0(8, data_020675b4);
    func_02003c54(0x104);
    func_02002d50(0xc);
    data_020675b0 = 8;
}
