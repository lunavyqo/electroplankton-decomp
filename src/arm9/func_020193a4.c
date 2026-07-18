// addr 0x020193a4 size 0x28 — clear slot +0x4c, tail func_02019684(slot+0x5c)

extern unsigned char *data_0208f854;

void func_02019684(int a);

void func_020193a4(int idx) {
    unsigned char *p = data_0208f854 + (idx << 2);
    *(int *)(p + 0x4c) = 0;
    func_02019684(*(int *)(p + 0x5c));
}
