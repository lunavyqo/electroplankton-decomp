// addr 0x02028ef4 size 0x74

void func_02004268(int a, int b, int c, int d);

void func_02028ef4(int a, int b, int c, int d) {
    if (a < 0) {
        a = 0;
    } else if (a >= 6) {
        a = 5;
    }
    if (c < -0x40) {
        c = -0x40;
    } else if (c > 0x3f) {
        c = 0x3f;
    }
    func_02004268(a, b % 360, c, d);
}
