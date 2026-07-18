// addr 0x0204e6d0 size 0x20

void func_0204e6d0(int *self, int a, int b) {
    if (b == 0) {
        a = 0;
    } else if (a == 0) {
        b = 0;
    }
    self[0x48 / 4] = a;
    self[0x4c / 4] = b;
}
