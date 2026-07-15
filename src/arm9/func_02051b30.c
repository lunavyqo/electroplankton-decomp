// addr 0x02051b30 size 0x88

// pools: 0x0209477c (u16 flag), 0x02094780 (struct), 0x020514e0 (handler)

unsigned short DAT_0209477c;

typedef struct {
    int f00;
    int f04;
    int f08;
    int f0c;
    int _10[3];
    int f1c;
} S;

S DAT_02094780;

void func_0204d710(void);
int func_0204d8f4(int a, int b);
void func_0204d91c(int a, void *handler);
void func_020514e0(void);

void func_02051b30(void) {
    if (DAT_0209477c != 0) {
        return;
    }
    DAT_0209477c = 1;
    DAT_02094780.f00 = 0;
    DAT_02094780.f04 = 0;
    DAT_02094780.f1c = 0;
    DAT_02094780.f08 = 0;
    DAT_02094780.f0c = 0;
    func_0204d710();
    while (func_0204d8f4(5, 1) == 0) {
    }
    func_0204d91c(5, (void *)func_020514e0);
}
