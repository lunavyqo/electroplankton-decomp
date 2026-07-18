// addr 0x02045adc size 0x18 — if field+8 < field+0xc then field+8++
void func_02045adc(int *p) {
    if (p[2] < p[3]) {
        p[2] = p[2] + 1;
    }
}
