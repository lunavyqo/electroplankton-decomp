// addr 0x02017284 size 0x14
// tail-call trampoline to 0x02014fdc with bitfield extract on arg1
void func_02014fdc(int a, int b);

void func_02017284(int a, int b) {
    func_02014fdc(a, (b << 4) >> 12);
}
