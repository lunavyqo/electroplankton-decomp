// addr 0x020024bc size 0x28

int func_02002570(void);
void func_02045db0(int a);

void func_020024bc(void) {
    func_02045db0(func_02002570() & 0x0ffff000);
}
