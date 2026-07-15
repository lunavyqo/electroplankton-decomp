// addr 0x02052ba8 size 0x60

extern int data_02095054;
void func_02052b88(void);
void func_0204b7d4(void);

void func_02052ba8(int a, int msg)
{
    int r;
    int (*cb)(void);

    if ((msg & 0x3f) == 0x11) {
        r = 0;
        cb = (int (*)(void))data_02095054;
        if (cb != 0)
            r = cb();
        if (r == 0)
            return;
        func_02052b88();
    } else {
        func_0204b7d4();
    }
}
