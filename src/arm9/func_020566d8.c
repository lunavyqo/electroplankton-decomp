// addr 0x020566d8 size 0x3c
// Soft-float <= : NaN → false; map signed float bits then signed int compare.
//
//   int func_020566d8(int a, int b) {
//       unsigned lim = 0xFF000000u;
//       if (lim < ((unsigned)a << 1) || lim < ((unsigned)b << 1)) return 0;
//       if (a < 0) { a &= ~0x80000000; a = -a; }
//       if (b < 0) { b &= ~0x80000000; b = -b; }
//       return a <= b;
//   }

asm int func_020566d8(int a, int b) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    movlo r0, #0
    bxlo lr
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movle r0, #1
    movgt r0, #0
    bx lr
}
