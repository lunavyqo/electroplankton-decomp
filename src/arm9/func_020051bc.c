// addr 0x020051bc size 0x30

extern unsigned char *data_0206f240;

void func_020426a8(void *p);

void func_020051bc(void) {
    *(int *)(data_0206f240 + 0x4c) = 0;
    *(int *)(data_0206f240 + 0x50) = 0;
    func_020426a8(*(void **)data_0206f240);
}
