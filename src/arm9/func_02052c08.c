// addr 0x02052c08 size 0x3c

extern unsigned short data_02095048[];
void func_0204b7d4(void);

void func_02052c08(int a, int msg)
{
    if ((msg & 0x3f) == 1) {
        data_02095048[0] = 1;
        return;
    }
    func_0204b7d4();
}
