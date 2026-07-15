// addr 0x02057630 size 0x278
// _f_sub — single-precision sub (soft-float) (MWCC soft-float runtime)

void ext_0205634c(void);
asm void func_02057630()
{
    eors r2, r0, r1
    eormi r1, r1, #0x80000000
    bmi ext_0205634c
    subs ip, r0, r1
    eorlo ip, ip, #0x80000000
    sublo r0, r0, ip
    addlo r1, r1, ip
    mov r2, #0x80000000
    mov r3, r0, lsr #0x17
    orr r0, r2, r0, lsl #8
    ands ip, r3, #0xff
    cmpne ip, #0xff
    beq loc_02057758
    mov ip, r1, lsr #0x17
    orr r1, r2, r1, lsl #8
    ands r2, ip, #0xff
    beq loc_02057798
loc_02057674:
    subs ip, r3, ip
    beq loc_020576bc
    rsb r2, ip, #0x20
    movs r2, r1, lsl r2
    mov r1, r1, lsr ip
    orrne r1, r1, #1
    subs r0, r0, r1
    bpl loc_02057700
    ands r1, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    tst r1, #0x80
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
loc_020576bc:
    subs r0, r0, r1
    beq loc_02057864
    mov r2, r3, lsl #0x17
    and r2, r2, #0x80000000
    bic r3, r3, #0x100
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    cmp r3, #0
    bgt loc_020576f0
    rsb r3, r3, #9
    orr r0, r2, r0, lsr r3
    bx lr
loc_020576f0:
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
loc_02057700:
    mov r2, r3, lsl #0x17
    and r2, r2, #0x80000000
    bic r3, r3, #0x100
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    cmp r3, #0
    bgt loc_0205772c
    rsb r3, r3, #9
    orr r0, r2, r0, lsr r3
    bx lr
loc_0205772c:
    ands r1, r0, #0xff
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r1, #0x80
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
loc_02057758:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    ands r3, r3, #0xff
    beq loc_020577c0
    movs r0, r0, lsl #1
    bne loc_02057898
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq loc_0205788c
    cmp ip, #0xff
    blt loc_0205788c
    cmp r1, #0
    beq loc_020578a0
    b loc_02057898
loc_02057798:
    cmp ip, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    and r3, r3, #0xff
    ands ip, ip, #0xff
    beq loc_02057828
loc_020577b0:
    eor r2, r2, #0x80000000
    movs r1, r1, lsl #1
    bne loc_02057898
    b loc_0205788c
loc_020577c0:
    movs r0, r0, lsl #1
    beq loc_020577f8
    mov r0, r0, lsr #1
    mov r3, #1
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq loc_02057828
    cmp ip, #0xff
    beq loc_020577b0
    orr r1, r1, #0x80000000
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    b loc_02057674
loc_020577f8:
    mov r3, r1, lsr #0x17
    mov r0, r1, lsl #9
    ands r2, r3, #0xff
    beq loc_0205781c
    cmp r2, #0xff
    blt loc_02057844
    cmp r0, #0
    bne loc_02057884
    b loc_0205788c
loc_0205781c:
    cmp r0, #0
    beq loc_02057864
    b loc_02057844
loc_02057828:
    movs r1, r1, lsl #1
    beq loc_0205784c
    mov r1, r1, lsr #1
    mov ip, #1
    orr ip, ip, r2, lsr #23
    orr r3, r3, r2, lsr #23
    b loc_02057674
loc_02057844:
    mov r0, r1
    bx lr
loc_0205784c:
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
loc_02057864:
    mov r0, #0
    bx lr
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
loc_02057884:
    mvn r0, #0x80000000
    bx lr
loc_0205788c:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
loc_02057898:
    mvn r0, #0x80000000
    bx lr
loc_020578a0:
    mvn r0, #0x80000000
    bx lr
}
