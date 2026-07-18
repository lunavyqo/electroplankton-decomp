// addr 0x020100f0 size 0x10 — trampoline: r0=r1; tail to func_020103f0

void func_020103f0(void *arg);

void func_020100f0(void *unused, void *arg) {
    func_020103f0(arg);
}
