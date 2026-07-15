// addr 0x02056974 size 0x88
// _d_fneq — double != (NaN → true) (MWCC soft-float runtime)
asm void func_02056974()
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_020569c8
    cmn ip, r3, lsl #1
    bhs loc_020569e4
loc_02056988:
    orrs ip, r3, r1
    bmi loc_020569a4
    cmp r1, r3
    cmpeq r0, r2
    movne r0, #1
    moveq r0, #0
    bx lr
loc_020569a4:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movne r0, #1
    moveq r0, #0
    bx lr
loc_020569c8:
    movne r0, #1
    bxne lr
    cmp r0, #0
    movhi r0, #1
    bxhi lr
    cmn ip, r3, lsl #1
    blo loc_02056988
loc_020569e4:
    movne r0, #1
    bxne lr
    cmp r2, #0
    movhi r0, #1
    bxhi lr
    b loc_02056988
}
