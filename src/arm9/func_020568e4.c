// addr 0x020568e4 size 0x90
// _d_fcmp — double compare → 0/1/2/3 (duplicate of 0x2056854) (MWCC soft-float runtime)
asm void func_020568e4()
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_02056940
    cmn ip, r3, lsl #1
    bhs loc_0205695c
loc_020568f8:
    orrs ip, r3, r1
    bmi loc_02056918
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #0
    movlo r0, #1
    movhi r0, #2
    bx lr
loc_02056918:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    moveq r0, #0
    movlo r0, #1
    movhi r0, #2
    bx lr
loc_02056940:
    movne r0, #3
    bxne lr
    cmp r0, #0
    movhi r0, #3
    bxhi lr
    cmn ip, r3, lsl #1
    blo loc_020568f8
loc_0205695c:
    movne r0, #3
    bxne lr
    cmp r2, #0
    movhi r0, #3
    bxhi lr
    b loc_020568f8
}
