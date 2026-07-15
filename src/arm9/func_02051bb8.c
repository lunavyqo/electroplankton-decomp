// addr 0x02051bb8 size 0x34
int func_0204d840(int a, int b, int c);

int func_02051bb8(int arg) {
    int r = func_0204d840(5, (arg << 8) & 0x7f00, 0);
    if (r >= 0) {
        return 1;
    }
    return 0;
}
