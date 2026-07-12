// addr 0x020011c8 size 0x24

extern int data_02065c90[5];

void func_020011c8(void) {
    int i;
    int zero;

    zero = 0;
    i = zero;
    while (i < 5) {
        data_02065c90[i] = zero;
        i++;
    }
}
