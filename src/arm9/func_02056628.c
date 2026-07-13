// addr 0x02056628 size 0x3c
// Soft-float == : NaN → false; both ±0 → true; else bit equality.
//
//   int func_02056628(unsigned a, unsigned b) {
//       unsigned lim = 0xFF000000u;
//       if (lim < (a << 1)) return 0;
//       if (lim < (b << 1)) return 0;
//       if (((a | b) << 1) == 0) return 1;
//       return a == b;
//   }

asm int func_02056628(unsigned a, unsigned b) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    movlo r0, #0
    bxlo lr
    cmp r3, r1, lsl #1
    movlo r0, #0
    bxlo lr
    orr r3, r0, r1
    movs r3, r3, lsl #1
    moveq r0, #1
    bxeq lr
    cmp r0, r1
    moveq r0, #1
    movne r0, #0
    bx lr
}
