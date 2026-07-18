// addr 0x020495b4 size 0x10 — trampoline to func_020495c4(..., 0)

void func_020495c4(void *a, void *b, void *c, int d);

void func_020495b4(void *a, void *b, void *c) {
    func_020495c4(a, b, c, 0);
}
