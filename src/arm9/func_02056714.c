// addr 0x02056714 size 0x44
// Soft-float compare setting APSR (signaling / unordered-NaN path).
// On NaN: adds 0xff000000 + 0x10000000 into r2 (flags), return.
// Both ±0: set Z and return. Else cmp with sign-aware operand order.
//
//   // Flag-returning helper; no clean bool C equivalent under mwcc -O4,p.

asm void func_02056714(unsigned a, unsigned b) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    bhs ordered
    mov r2, #0xff000000
    adds r2, r2, #0x10000000
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
