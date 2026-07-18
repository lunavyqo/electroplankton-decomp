// addr 0x02015038 size 0x24 — clear 16 words at data_0208f49c

extern int data_0208f49c[];

void func_02015038(void) {
    int i = 0;
    int zero = 0;
    do {
        data_0208f49c[i] = zero;
        i = i + 1;
    } while (i < 0x10);
}
