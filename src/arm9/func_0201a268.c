// addr 0x0201a268 size 0x28 — find first zero slot in 50-entry table

int func_0201a268(int *arr) {
    int i = 0;
    do {
        if (arr[i] == 0) {
            return i;
        }
        i = i + 1;
    } while (i < 0x32);
    return 0;
}
