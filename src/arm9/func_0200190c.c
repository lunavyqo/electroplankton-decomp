// addr 0x0200190c size 0x34

extern int data_02065d10[];
extern int data_02065d4c[];

void func_0200190c(void) {
    int i;
    int zero;
    i = 0;
    zero = 0;
    do {
        data_02065d10[i] = zero;
        data_02065d4c[i] = data_02065d10[i];
        i++;
    } while (i < 0xf);
}
