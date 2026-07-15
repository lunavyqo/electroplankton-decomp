// addr 0x02052e10 size 0x9c

extern int data_02095050;
extern int data_02095054;
extern char data_02052c08;
extern char data_02052ba8;

void func_02052b48(void);
void func_0204d710(void);
int func_0204d8f4(int a, int b);
void func_0204d91c(int a, void *b);
void func_02052c44(void);

void func_02052e10(void)
{
    if (data_02095050 != 0)
        return;
    data_02095050 = 1;
    func_02052b48();
    func_0204d710();
    while (func_0204d8f4(0xd, 1) == 0)
        ;
    func_0204d91c(0xd, &data_02052c08);
    func_02052c44();
    func_0204d91c(0xd, 0);
    func_0204d91c(0xd, &data_02052ba8);
    data_02095054 = 0;
}
