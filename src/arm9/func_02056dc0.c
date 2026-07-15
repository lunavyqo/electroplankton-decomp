// addr 0x02056dc0 size 0x94
// _d_fcmp flags — ordered cmp leaves APSR; unord via adds #0 (MWCC soft-float runtime)
asm void func_02056dc0()
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_02056e04
    cmn ip, r3, lsl #1
    bhs loc_02056e30
loc_02056dd4:
    orrs ip, r3, r1
    bmi loc_02056de8
    cmp r1, r3
    cmpeq r0, r2
    bx lr
loc_02056de8:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    cmpeq r1, r1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    bx lr
loc_02056e04:
    beq loc_02056e14
    mov ip, #0
    adds ip, ip, #0
    bx lr
loc_02056e14:
    cmp r0, #0
    bls loc_02056e28
    mov ip, #0
    adds ip, ip, #0
    bx lr
loc_02056e28:
    cmn ip, r3, lsl #1
    blo loc_02056dd4
loc_02056e30:
    beq loc_02056e40
    mov ip, #0
    adds ip, ip, #0
    bx lr
loc_02056e40:
    cmp r2, #0
    bls loc_02056dd4
    mov ip, #0
    adds ip, ip, #0
    bx lr
}
