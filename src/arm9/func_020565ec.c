// addr 0x020565ec size 0x3c
// Soft-float != : NaN → true; both ±0 → false; else bit inequality.
// Equivalent C does not emit cmp Rm, Rn, lsl under -O4,p (uses lsl+cmp imm).
//
//   int func_020565ec(unsigned a, unsigned b) {
//       unsigned lim = 0xFF000000u;
//       if (lim < (a << 1)) return 1;
//       if (lim < (b << 1)) return 1;
//       if (((a | b) << 1) == 0) return 0;
//       return a != b;
//   }

asm int func_020565ec(unsigned a, unsigned b) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    movlo r0, #1
    bxlo lr
    cmp r3, r1, lsl #1
    movlo r0, #1
    bxlo lr
    orr r3, r0, r1
    movs r3, r3, lsl #1
    moveq r0, #0
    bxeq lr
    cmp r0, r1
    movne r0, #1
    moveq r0, #0
    bx lr
}
