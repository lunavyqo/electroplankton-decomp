// addr 0x02004b7c size 0x28

extern unsigned char *data_0206f038;

void func_02004b7c(int a) {
    if (a >= 2) {
        do {
            a -= 2;
        } while (a >= 2);
    }
    *(int *)(data_0206f038 + 0xc) = a;
}
