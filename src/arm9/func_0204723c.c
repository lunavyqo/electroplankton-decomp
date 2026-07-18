// addr 0x0204723c size 0x20 — VRAM bank base from IO 0x04001008 bits 2-5
int func_0204723c(void) {
    return (((int)(*(volatile unsigned short *)0x04001008 & 0x3c)) >> 2) * 0x4000 + 0x6200000;
}
