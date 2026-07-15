// addr 0x020569fc size 0x88
// _d_feq — double == (NaN → false) (MWCC soft-float runtime)
asm void func_020569fc()
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_02056a50
    cmn ip, r3, lsl #1
    bhs loc_02056a6c
loc_02056a10:
    orrs ip, r3, r1
    bmi loc_02056a2c
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #1
    movne r0, #0
    bx lr
loc_02056a2c:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    moveq r0, #1
    movne r0, #0
    bx lr
loc_02056a50:
    movne r0, #0
    bxne lr
    cmp r0, #0
    movhi r0, #0
    bxhi lr
    cmn ip, r3, lsl #1
    blo loc_02056a10
loc_02056a6c:
    movne r0, #0
    bxne lr
    cmp r2, #0
    movhi r0, #0
    bxhi lr
    b loc_02056a10
}
