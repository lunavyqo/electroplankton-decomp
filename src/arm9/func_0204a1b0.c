// addr 0x0204a1b0 size 0x14 — enable IRQs then infinite WFI loop
void func_0204b744(void);
void func_0204b7bc(void);

void func_0204a1b0(void) {
    func_0204b744();
    for (;;) {
        func_0204b7bc();
    }
}
