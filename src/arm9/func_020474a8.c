// addr 0x020474a8 size 0x20 — VRAM bank base from IO 0x0400100a bits 8-12
int func_020474a8(void) {
    return (((int)(*(volatile unsigned short *)0x0400100a & 0x1f00)) >> 8) * 0x800 + 0x6200000;
}
