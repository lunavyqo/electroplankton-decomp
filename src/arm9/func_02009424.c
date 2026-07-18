// addr 0x02009424 size 0x14 — store 1 to IO

extern volatile int data_04000540;

void func_02009424(void) {
    data_04000540 = 1;
}
