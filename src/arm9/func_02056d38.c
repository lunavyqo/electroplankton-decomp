// addr 0x02056d38 size 0x88
// _d_fge — double >= (NaN → false) (MWCC soft-float runtime)
asm void func_02056d38()
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_02056d8c
    cmn ip, r3, lsl #1
    bhs loc_02056da8
loc_02056d4c:
    orrs ip, r3, r1
    bmi loc_02056d68
    cmp r1, r3
    cmpeq r0, r2
    movhs r0, #1
    movlo r0, #0
    bx lr
loc_02056d68:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movhs r0, #1
    movlo r0, #0
    bx lr
loc_02056d8c:
    movne r0, #0
    bxne lr
    cmp r0, #0
    movhi r0, #0
    bxhi lr
    cmn ip, r3, lsl #1
    blo loc_02056d4c
loc_02056da8:
    movne r0, #0
    bxne lr
    cmp r2, #0
    movhi r0, #0
    bxhi lr
    b loc_02056d4c
}
