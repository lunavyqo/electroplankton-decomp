// addr 0x0204b7d4 size 0x14 — infinite halt loop (disable IRQ + WFI)

unsigned int func_0204b758(void);
void func_0204b7bc(void);

void func_0204b7d4(void) {
    for (;;) {
        func_0204b758();
        func_0204b7bc();
    }
}
