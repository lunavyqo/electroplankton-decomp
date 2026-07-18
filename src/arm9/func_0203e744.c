// addr 0x0203e744 size 0x13c

typedef signed short s16;

void func_020015e4(void *p);
void func_02047764(void *p);
void func_020475b4(void *p, int a);
void func_02047654(void *p, int a, int b);
void func_02047614(void *p, int a, int b, int c);
void func_02047590(void *p);
void func_0204773c(void *p, int a);
void func_020015c0(void *p);

extern int data_020654ac[];
extern int data_0206546c[];

void func_0203e744(void *param) {
    int *a = data_020654ac;
    int *b = data_0206546c;

    func_020015e4(param);
    func_02047764(param);
    func_020475b4(param, 1);

    func_02047654(param, a[0], a[1]);
    func_02047614(param, (s16)b[0], (s16)b[1], 0);

    func_02047654(param, a[2], a[3]);
    func_02047614(param, (s16)b[2], (s16)b[3], 0);

    func_02047654(param, a[4], a[5]);
    func_02047614(param, (s16)b[4], (s16)b[5], 0);

    func_02047654(param, a[6], a[7]);
    func_02047614(param, (s16)b[6], (s16)b[7], 0);

    func_02047590(param);
    func_0204773c(param, 1);
    func_020015c0(param);
}
