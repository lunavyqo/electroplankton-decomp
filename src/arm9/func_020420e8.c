// addr 0x020420e8 size 0x18 — copy +0x18 to +0x24; clear +0x2c via mid ptr
void func_020420e8(int *p) {
    int *mid = p + 9;
    *mid = p[6];
    mid[2] = 0;
}
