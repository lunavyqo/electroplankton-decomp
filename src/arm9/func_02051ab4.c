// addr 0x02051ab4 size 0x7c

int DAT_02094780;

int func_0204b758(void);
void func_0204b76c(int);
int func_02051bfc(void);

int func_02051ab4(int a, int b, int c) {
    int enabled = func_0204b758();
    if (DAT_02094780 != 0) {
        func_0204b76c(enabled);
        return 1;
    }
    DAT_02094780 = 1;
    func_0204b76c(enabled);
    ((int *)&DAT_02094780)[0x14 / 4] = 1;
    ((int *)&DAT_02094780)[0x18 / 4] = 0;
    ((int *)&DAT_02094780)[0x8 / 4] = a;
    ((int *)&DAT_02094780)[0x4 / 4] = b;
    ((int *)&DAT_02094780)[0x10 / 4] = c;
    {
        int r = func_02051bfc();
        if (r != 0) {
            return 0;
        } else {
            return 3;
        }
    }
}
