// addr 0x02056ea8 size 0x50
// _d_ford — double isordered (NaN → 0) (MWCC soft-float runtime)
asm void func_02056ea8()
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs loc_02056ec4
    cmn ip, r3, lsl #1
    bhs loc_02056ee0
loc_02056ebc:
    mov r0, #1
    bx lr
loc_02056ec4:
    movne r0, #0
    bxne lr
    cmp r0, #0
    movhi r0, #0
    bxhi lr
    cmn ip, r3, lsl #1
    blo loc_02056ebc
loc_02056ee0:
    movne r0, #0
    bxne lr
    cmp r2, #0
    movhi r0, #0
    bxhi lr
    b loc_02056ebc
}
