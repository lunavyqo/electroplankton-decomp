// addr 0x02056b90 size 0x88
// _d_fle — double <= (NaN → false) (MWCC soft-float runtime)
asm void func_02056b90()
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_02056be4
    cmn ip, r3, lsl #1
    bhs loc_02056c00
loc_02056ba4:
    orrs ip, r3, r1
    bmi loc_02056bc0
    cmp r1, r3
    cmpeq r0, r2
    movls r0, #1
    movhi r0, #0
    bx lr
loc_02056bc0:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movls r0, #1
    movhi r0, #0
    bx lr
loc_02056be4:
    movne r0, #0
    bxne lr
    cmp r0, #0
    movhi r0, #0
    bxhi lr
    cmn ip, r3, lsl #1
    blo loc_02056ba4
loc_02056c00:
    movne r0, #0
    bxne lr
    cmp r2, #0
    movhi r0, #0
    bxhi lr
    b loc_02056ba4
}
