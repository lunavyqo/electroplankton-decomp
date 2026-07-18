// addr 0x020474fc size 0x20 — VRAM bank base from IO 0x04001008 bits 8-12
int func_020474fc(void) {
    return (((int)(*(volatile unsigned short *)0x04001008 & 0x1f00)) >> 8) * 0x800 + 0x6200000;
}
