// addr 0x02009710 size 0x18 — load *data_0208938c; if 0 return 2

extern int data_0208938c;

int func_02009710(void) {
    int v = data_0208938c;
    if (v == 0) {
        v = 2;
    }
    return v;
}
