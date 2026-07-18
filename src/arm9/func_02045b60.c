// addr 0x02045b60 size 0x20 — zero four words via copy chain
void func_02045b60(unsigned int *p) {
    p[1] = 0;
    p[0] = p[1];
    p[3] = 0;
    p[2] = p[3];
}
