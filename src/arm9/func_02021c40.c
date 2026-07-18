// addr 0x02021c40 size 0xc — trampoline to func_02001068

void *func_02001068(void *arg);

void *func_02021c40(void *arg) {
    return func_02001068(arg);
}
