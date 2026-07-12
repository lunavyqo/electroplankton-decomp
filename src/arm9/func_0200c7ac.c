// Infinite event/callback loop
// addr 0x0200c7ac size 0x40

extern void *data_020898cc;
extern unsigned char data_02071334;
extern void (*volatile data_020898d0)(void *);

void func_0204a46c(void *obj);

void func_0200c7ac(void) {
    for (;;) {
        if (data_020898d0 != 0) {
            data_020898d0(data_020898cc);
        }
        func_0204a46c(&data_02071334);
    }
}
