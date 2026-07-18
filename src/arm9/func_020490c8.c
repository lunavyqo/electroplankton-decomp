// addr 0x020490c8 size 0x20 — init ring/buffer struct fields
void func_020490c8(int *p, int a, int b) {
    p[3] = b;
    p[2] = a;
    p[0] = a;
    p[1] = a + 4;
    p[4] = 0;
}
