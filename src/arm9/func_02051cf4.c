// NONMATCHING: prologue r2 vs r3 for zero; field14/p00 vs call-arg schedule (div=8)
// addr 0x02051cf4 size 0xf8

int DAT_02094800;
int DAT_020947c0;
unsigned short DAT_027ffc40;
char DAT_027ffe00;
char DAT_027ffa80;
char DAT_020526a0;
char DAT_02094e00;
char DAT_020526fc;

void func_0204bf7c(int a, void *b, int c);
void func_0204af2c(void *a, int b);
void func_0204c05c(void *a, void *b, int c);
void func_0204a598(void *a, void *b, void *c, void *d, int e, int f);
void func_0204a3c4(void *a);
void func_0204d91c(int a, void *handler);
void func_02051ca8(int v);

void func_02051cf4(void) {
    char *g = (char *)&DAT_02094800;
    void *p = &DAT_020947c0;
    int c = 0x40;
    int owner = (int)~2;
    int z = 0;
    *(int *)(g + 8) = owner;
    *(int *)(g + 0xc) = z;
    {
        volatile int v = z;
        int a = v;
        *(int *)(g + 0x14) = z;
        *(void **)g = p;
        func_0204bf7c(a, p, c);
    }
    func_0204af2c(&DAT_020947c0, 0x40);
    if (DAT_027ffc40 != 2) {
        func_0204c05c(&DAT_027ffe00, &DAT_027ffa80, 0x160);
    }
    *(unsigned short *)(g + 0x10) = 0;
    *(unsigned short *)(g + 0xdc) = 0;
    *(int *)(g + 0xd8) = 4;
    func_0204a598(g + 0x40, &DAT_020526a0, 0, &DAT_02094e00, 0x400, *(int *)(g + 0xd8));
    func_0204a3c4(g + 0x40);
    func_0204d91c(0xb, &DAT_020526fc);
    if (DAT_027ffc40 == 2) {
        return;
    }
    func_02051ca8(1);
}
