// addr 0x02052800 size 0x6c

extern int data_02095044;
extern int data_02095040;
void func_020527b0(void);
void func_0204b7d4(void);

void func_02052800(int a, int msg)
{
    int r;
    int (*cb)(void);

    if ((msg & 0x3f) == 0x11) {
        cb = (int (*)(void))data_02095044;
        data_02095040 = 1;
        r = 1;
        if (cb != 0)
            r = cb();
        if (r == 0)
            return;
        func_020527b0();
    } else {
        func_0204b7d4();
    }
}
