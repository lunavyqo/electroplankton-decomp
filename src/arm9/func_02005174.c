// addr 0x02005174 size 0x48

extern unsigned char *data_0206f240;

void func_020426a8(void *p);

void func_02005174(void) {
    unsigned char *base = data_0206f240;
    if (*(int *)(base + 0x4c) == 1) {
        *(int *)(base + 0x4c) = 2;
        func_020426a8(*(void **)data_0206f240);
    }
}
