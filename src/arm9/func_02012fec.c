// addr 0x02012fec size 0x20 — countdown 9..0

void func_020130f0(int i);

void func_02012fec(void) {
    int i = 9;
    do {
        func_020130f0(i);
        i = i - 1;
    } while (i >= 0);
}
