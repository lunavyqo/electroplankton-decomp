// addr 0x02056a84 size 0x80
// _d_fcmp flags — ordered cmp leaves APSR; unord via movs #1 (MWCC soft-float runtime)
asm void func_02056a84()
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_02056ac4
    cmn ip, r3, lsl #1
    bhs loc_02056ae8
loc_02056a98:
    orrs ip, r3, r1
    bmi loc_02056aac
    cmp r1, r3
    cmpeq r0, r2
    bx lr
loc_02056aac:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    bx lr
loc_02056ac4:
    beq loc_02056ad0
    movs ip, #1
    bx lr
loc_02056ad0:
    cmp r0, #0
    bls loc_02056ae0
    movs ip, #1
    bx lr
loc_02056ae0:
    cmn ip, r3, lsl #1
    blo loc_02056a98
loc_02056ae8:
    beq loc_02056af4
    movs ip, #1
    bx lr
loc_02056af4:
    cmp r2, #0
    bls loc_02056a98
    movs ip, #1
    bx lr
}
