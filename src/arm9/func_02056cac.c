// addr 0x02056cac size 0x8c
// _d_fgt — double > (NaN → false); entry branches into 0x2056c2c (MWCC soft-float runtime)
void ext_02056c2c(void);
asm void func_02056cac()
{
    b ext_02056c2c
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_02056d04
    cmn ip, r3, lsl #1
    bhs loc_02056d20
loc_02056cc4:
    orrs ip, r3, r1
    bmi loc_02056ce0
    cmp r1, r3
    cmpeq r0, r2
    movhi r0, #1
    movls r0, #0
    bx lr
loc_02056ce0:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movhi r0, #1
    movls r0, #0
    bx lr
loc_02056d04:
    movne r0, #0
    bxne lr
    cmp r0, #0
    movhi r0, #0
    bxhi lr
    cmn ip, r3, lsl #1
    blo loc_02056cc4
loc_02056d20:
    movne r0, #0
    bxne lr
    cmp r2, #0
    movhi r0, #0
    bxhi lr
    b loc_02056cc4
}
