// addr 0x02052b48 size 0x40

extern unsigned short data_02095048[];
void CpuSet(const void *src, void *dst, unsigned int ctrl);
int func_020493ec(void);

void func_02052b48(void)
{
    unsigned int zero = 0;
    CpuSet(&zero, data_02095048, 0x05000001);
    data_02095048[1] = (unsigned short)func_020493ec();
}
