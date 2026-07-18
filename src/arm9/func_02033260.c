// addr 0x02033260 size 0xc — trampoline to func_02001068

void *func_02001068(void *arg);

void *func_02033260(void *arg) {
    return func_02001068(arg);
}
