// addr 0x02005ec0 size 0x74

extern int data_020675b0;
extern void *data_0206f554;

void func_02043100(void *p);
void func_02002910(void);

void func_02005ec0(void) {
    int i;
    int j;

    data_020675b0 = 0xff;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            func_02043100((char *)data_0206f554 + i * 0xc + j * 4);
        }
    }
    func_02002910();
}
