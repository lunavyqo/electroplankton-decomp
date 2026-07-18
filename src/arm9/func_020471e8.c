// addr 0x020471e8 size 0x20 — VRAM bank base from IO 0x0400100a bits 2-5
int func_020471e8(void) {
    return (((int)(*(volatile unsigned short *)0x0400100a & 0x3c)) >> 2) * 0x4000 + 0x6200000;
}
