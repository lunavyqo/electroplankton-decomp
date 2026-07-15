// addr 0x02052930 size 0x80

int func_0204b758(void);
int func_02049454(void *p);
int func_020494f4(int a);
void func_0204b76c(int a);
void func_020004e4(int a);

void func_02052930(int a, int *buf)
{
    void *p = (void *)0x027fffe8;
    int one = 1;
loop:
    buf[1] = func_0204b758();
    buf[0] = func_02049454(p) & 0x40;
    if (buf[0] != 0)
        return;
    if (func_020494f4(a) == 0)
        return;
    func_0204b76c(buf[1]);
    func_020004e4(one);
    goto loop;
}
