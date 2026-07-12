// addr 0x02000f1c size 0xc — trampoline to func_02001068

void *func_02001068(void *arg);

void *func_02000f1c(void *arg) {
    return func_02001068(arg);
}
