// addr 0x020572bc size 0x84
// _f_ftod — float to double (soft-float) (MWCC soft-float runtime)
asm void func_020572bc()
{
    and r2, r0, #0x80000000
    mov ip, r0, lsr #0x17
    mov r3, r0, lsl #9
    ands ip, ip, #0xff
    beq loc_020572ec
    cmp ip, #0xff
    beq loc_02057318
loc_020572d8:
    add ip, ip, #0x380
    mov r0, r3, lsl #0x14
    orr r1, r2, r3, lsr #12
    orr r1, r1, ip, lsl #20
    bx lr
loc_020572ec:
    cmp r3, #0
    bne loc_02057300
    mov r1, r2
    mov r0, #0
    bx lr
loc_02057300:
    mov r3, r3, lsr #1
    clz ip, r3
    movs r3, r3, lsl ip
    rsb ip, ip, #1
    add r3, r3, r3
    b loc_020572d8
loc_02057318:
    cmp r3, #0
    bhi loc_02057330
    ldr r1, [pc, #0x14]
    orr r1, r1, r2
    mov r0, #0
    bx lr
loc_02057330:
    mvn r0, #0
    bic r1, r0, #0x80000000
    bx lr
    dcd 0x7FF00000
}
