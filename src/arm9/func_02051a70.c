// addr 0x02051a70 size 0x44

// pools: 0x0205144c (func ptr / handler), 0x02094780 (state)

typedef struct {
    char _00[0x20];
    int field20;
} State;

State DAT_02094780;
void *DAT_0205144c; // actually a function address used as arg - it's code, passed as r1

int func_02051ab4(int a, void *b, int c);
void func_02051434(void);

int func_02051a70(int a) {
    int r;
    r = func_02051ab4(a, (void *)0x0205144c, 0);
    DAT_02094780.field20 = r;
    if (r == 0) {
        func_02051434();
    }
    return DAT_02094780.field20;
}
