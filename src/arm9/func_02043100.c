// addr 0x02043100 size 0x18 — if *p: **p = 0; *p = 0
void func_02043100(unsigned int **p) {
    unsigned int *q = *p;
    if (q != 0) {
        *q = 0;
        *p = 0;
    }
}
