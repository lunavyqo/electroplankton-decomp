// addr 0x020527b0 size 0x40

void func_02050d60(void);
void func_0205274c(int a, int b);
void func_0204b7d4(void);

void func_020527b0(void)
{
    unsigned short *p = (unsigned short *)0x027fffa8;
    if ((*p & 0x8000) >> 15)
        func_02050d60();
    func_0205274c(1, 1);
    func_0204b7d4();
}
