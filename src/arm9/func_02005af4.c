// addr 0x02005af4 size 0x5c

void func_02043124(void *p, int a);
void func_020430f0(void *p, int a);

void func_02005af4(int *p, int mode) {
    if (mode == 0) {
        if (*p == 0) {
            return;
        }
        func_02043124(p, 0);
        return;
    }
    if (*p == 0) {
        return;
    }
    func_020430f0(p, mode);
}
