// addr 0x02056b04 size 0x8c
// _d_flt — double < (NaN → false); entry branches into 0x2056a98 (MWCC soft-float runtime)
void ext_02056a98(void);
asm void func_02056b04()
{
    b ext_02056a98
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_02056b5c
    cmn ip, r3, lsl #1
    bhs loc_02056b78
loc_02056b1c:
    orrs ip, r3, r1
    bmi loc_02056b38
    cmp r1, r3
    cmpeq r0, r2
    movlo r0, #1
    movhs r0, #0
    bx lr
loc_02056b38:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movlo r0, #1
    movhs r0, #0
    bx lr
loc_02056b5c:
    movne r0, #0
    bxne lr
    cmp r0, #0
    movhi r0, #0
    bxhi lr
    cmn ip, r3, lsl #1
    blo loc_02056b1c
loc_02056b78:
    movne r0, #0
    bxne lr
    cmp r2, #0
    movhi r0, #0
    bxhi lr
    b loc_02056b1c
}
