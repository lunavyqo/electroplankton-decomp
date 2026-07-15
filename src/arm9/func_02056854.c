// addr 0x02056854 size 0x90
// _d_fcmp — double compare → 0/1/2/3 (eq/lt/gt/unord) (MWCC soft-float runtime)
asm void func_02056854()
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_020568b0
    cmn ip, r3, lsl #1
    bhs loc_020568cc
loc_02056868:
    orrs ip, r3, r1
    bmi loc_02056888
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #0
    movlo r0, #1
    movhi r0, #2
    bx lr
loc_02056888:
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
loc_020568b0:
    movne r0, #3
    bxne lr
    cmp r0, #0
    movhi r0, #3
    bxhi lr
    cmn ip, r3, lsl #1
    blo loc_02056868
loc_020568cc:
    movne r0, #3
    bxne lr
    cmp r2, #0
    movhi r0, #3
    bxhi lr
    b loc_02056868
}
