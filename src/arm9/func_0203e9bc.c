// addr 0x0203e9bc size 0x3c

void func_0203e9f8(void *a, void *b, unsigned short c);

void func_0203e9bc(void **self, void *arg) {
    int i;
    for (i = 2; i < 0x19; i++) {
        func_0203e9f8(self[i - 2], arg, (unsigned short)i);
    }
}
