// addr 0x02041644 size 0x18 — if q==0 return *p; else *(q + *(ush*)(p+10) + 4)
int func_02041644(void *p, void *q) {
    if (q == 0) {
        return *(int *)p;
    } else {
        return *(int *)((char *)q + *(unsigned short *)((char *)p + 10) + 4);
    }
}
