// addr 0x0204c99c size 0x20 — 0x100 - func_0204c9fc() - func_0204c9bc()
int func_0204c9fc(void);
int func_0204c9bc(void);

int func_0204c99c(void) {
    int a = func_0204c9fc();
    int b = func_0204c9bc();
    return (0x100 - a) - b;
}
