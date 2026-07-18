// addr 0x02009728 size 0x20 — store (param==1? keep : 0) then tail to func_02003c88

extern unsigned int data_0208938c;
void func_02003c88(void);

void func_02009728(int param) {
    if (param != 1) {
        param = 0;
    }
    data_0208938c = param;
    func_02003c88();
}
