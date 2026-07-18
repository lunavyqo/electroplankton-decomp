// addr 0x020303e8 size 0xc — trampoline to func_02001068

void *func_02001068(void *arg);

void *func_020303e8(void *arg) {
    return func_02001068(arg);
}
