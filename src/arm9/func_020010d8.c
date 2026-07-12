// addr 0x020010d8 size 0x5c

extern int data_02065c80;
extern void *data_02065c84;

void *func_02041a3c(void *a, void *b, int c);
void func_0204b7d4(void);

void func_020010d8(void *a, void *b) {
    if (data_02065c80 != 0) {
        return;
    }
    data_02065c84 = func_02041a3c(a, b, 0);
    if (data_02065c84 == 0) {
        func_0204b7d4();
    }
    data_02065c80 = 1;
}
