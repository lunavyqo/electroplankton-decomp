// addr 0x0203d12c size 0x24

extern unsigned char *data_02090f8c;

int func_020407f4(void *p);

void func_0203d12c(void) {
    unsigned char *obj = data_02090f8c;
    int v = func_020407f4(obj + 0x90);
    *(int *)(obj + 0x44) = v;
}
