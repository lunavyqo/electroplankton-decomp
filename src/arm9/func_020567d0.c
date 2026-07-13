// addr 0x020567d0 size 0x3c
// Soft-float compare setting APSR (quiet NaN path: early return on NaN).
// Both ±0: set Z. Else cmp with sign-aware operand order.
//
//   // Flag-returning helper; no clean bool C equivalent under mwcc -O4,p.

asm void func_020567d0(unsigned a, unsigned b) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    bhs ordered
    bx lr
ordered:
    orr r3, r0, r1
    movs r3, r3, lsl #1
    cmpeq r0, r0
    bxeq lr
    orrs r2, r0, r1
    bmi neg
    cmp r0, r1
    bx lr
neg:
    cmp r1, r0
    bx lr
}
