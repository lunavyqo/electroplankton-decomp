// addr 0x02056c18 size 0x94
// _d_fcmp flags — ordered cmp leaves APSR; unord via adds 0xff000000+0x10000000 (MWCC soft-float runtime)
asm void func_02056c18()
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_02056c5c
    cmn ip, r3, lsl #1
    bhs loc_02056c88
loc_02056c2c:
    orrs ip, r3, r1
    bmi loc_02056c40
    cmp r1, r3
    cmpeq r0, r2
    bx lr
loc_02056c40:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    cmpeq r1, r1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    bx lr
loc_02056c5c:
    beq loc_02056c6c
    mov ip, #0xff000000
    adds ip, ip, #0x10000000
    bx lr
loc_02056c6c:
    cmp r0, #0
    bls loc_02056c80
    mov ip, #0xff000000
    adds ip, ip, #0x10000000
    bx lr
loc_02056c80:
    cmn ip, r3, lsl #1
    blo loc_02056c2c
loc_02056c88:
    beq loc_02056c98
    mov ip, #0xff000000
    adds ip, ip, #0x10000000
    bx lr
loc_02056c98:
    cmp r2, #0
    bls loc_02056c2c
    mov ip, #0xff000000
    adds ip, ip, #0x10000000
    bx lr
}
