// addr 0x02056e54 size 0x54
// _d_funord — double isunordered (NaN → 1); entry branches into 0x2056dd4 (MWCC soft-float runtime)
void ext_02056dd4(void);
asm void func_02056e54()
{
    b ext_02056dd4
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_02056e74
    cmn ip, r3, lsl #1
    bhs loc_02056e90
loc_02056e6c:
    mov r0, #0
    bx lr
loc_02056e74:
    movne r0, #1
    bxne lr
    cmp r0, #0
    movhi r0, #1
    bxhi lr
    cmn ip, r3, lsl #1
    blo loc_02056e6c
loc_02056e90:
    movne r0, #1
    bxne lr
    cmp r2, #0
    movhi r0, #1
    bxhi lr
    b loc_02056e6c
}
