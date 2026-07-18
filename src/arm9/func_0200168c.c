// addr 0x0200168c size 0x3c

extern int data_02065d4c[];
extern int data_02065d10[];

int func_0200168c(int mode, int idx, int add) {
    int prev;

    if (mode == 1) {
        prev = data_02065d10[idx];
        data_02065d10[idx] = data_02065d10[idx] + add;
    } else {
        prev = data_02065d4c[idx];
        data_02065d4c[idx] = data_02065d4c[idx] + add;
    }
    return prev;
}
