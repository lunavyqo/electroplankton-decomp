// NONMATCHING: regalloc — flag load/cmp uses r0 not r1 (div=2)
// addr 0x02052908 size 0x28

void func_020493e0(void);
void func_0204b76c(int a);

void func_02052908(int a, int *buf)
{
    int flag;

    flag = buf[0];
    if (flag == 0)
        func_020493e0();
    func_0204b76c(buf[1]);
}
