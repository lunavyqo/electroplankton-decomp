// addr 0x02028378 size 0x3c

void func_020283b4(void *p, void *arg, unsigned short idx);

void func_02028378(void **arr, void *arg) {
    int i;
    for (i = 2; i < 0x19; i++) {
        func_020283b4(arr[i - 2], arg, (unsigned short)i);
    }
}
