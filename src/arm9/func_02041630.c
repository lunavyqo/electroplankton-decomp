// addr 0x02041630 size 0x14
int func_02041630(void *p, void *q) {
    if (q == 0) {
        return *(int *)((char *)p + 4);
    } else {
        return *(int *)((char *)q + *(unsigned short *)((char *)p + 10));
    }
}
