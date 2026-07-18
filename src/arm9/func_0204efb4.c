// addr 0x0204efb4 size 0x10 — tail-call wrapper with r3=0

void func_0204f244(void *file, void *buf, int size, int flag);

void func_0204efb4(void *file, void *buf, int size) {
    func_0204f244(file, buf, size, 0);
}
