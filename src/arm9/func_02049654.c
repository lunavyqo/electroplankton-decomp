// addr 0x02049654 size 0x10 — trampoline to func_02049664(..., 0)

void func_02049664(void *a, void *b, void *c, int d);

void func_02049654(void *a, void *b, void *c) {
    func_02049664(a, b, c, 0);
}
