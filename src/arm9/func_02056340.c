// addr 0x02056340 size 0x21c
// _f_add — single-precision add (soft-float) (MWCC soft-float runtime)

void ext_0205763c(void);
asm void func_02056340()
{
    eors r2, r0, r1
    eormi r1, r1, #0x80000000
    bmi ext_0205763c
    subs ip, r0, r1
    sublo r0, r0, ip
    addlo r1, r1, ip
    mov r2, #0x80000000
    mov r3, r0, lsr #0x17
    orr r0, r2, r0, lsl #8
    ands ip, r3, #0xff
    cmpne ip, #0xff
    beq loc_020563e0
    mov ip, r1, lsr #0x17
    orr r1, r2, r1, lsl #8
    ands r2, ip, #0xff
    beq loc_02056420
loc_02056380:
    subs ip, r3, ip
    beq loc_02056398
    rsb r2, ip, #0x20
    movs r2, r1, lsl r2
    mov r1, r1, lsr ip
    orrne r1, r1, #1
loc_02056398:
    adds r0, r0, r1
    blo loc_020563b8
    and r1, r0, #1
    orr r0, r1, r0, rrx
    add r3, r3, #1
    and r2, r3, #0xff
    cmp r2, #0xff
    beq loc_02056528
loc_020563b8:
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
loc_020563e0:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    ands r3, r3, #0xff
    beq loc_02056444
    movs r0, r0, lsl #1
    bne loc_02056554
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq loc_02056548
    cmp ip, #0xff
    blt loc_02056548
    cmp r1, #0
    beq loc_02056548
    b loc_02056554
loc_02056420:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    and r3, r3, #0xff
    ands ip, ip, #0xff
    beq loc_020564a0
loc_02056438:
    movs r1, r1, lsl #1
    bne loc_02056554
    b loc_02056548
loc_02056444:
    movs r0, r0, lsl #1
    beq loc_0205647c
    mov r3, #1
    mov r0, r0, lsr #1
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq loc_020564a0
    cmp ip, #0xff
    beq loc_02056438
    orr r1, r1, #0x80000000
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    b loc_02056380
loc_0205647c:
    mov r3, r1, lsr #0x17
    mov r0, r1, lsl #9
    ands r3, r3, #0xff
    beq loc_02056508
    cmp r3, #0xff
    blt loc_02056508
    cmp r0, #0
    beq loc_02056548
    b loc_02056540
loc_020564a0:
    movs r1, r1, lsl #1
    beq loc_02056510
    mov r1, r1, lsr #1
    mov ip, #1
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    cmp r0, #0
    bmi loc_02056380
    adds r0, r0, r1
    blo loc_020564d4
    and r1, r0, #1
    orr r0, r1, r0, rrx
    add ip, ip, #1
loc_020564d4:
    cmp r0, #0
    subge ip, ip, #1
    ands r1, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, ip, lsl #23
    bxeq lr
    tst r1, #0x80
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
loc_02056508:
    mov r0, r1
    bx lr
loc_02056510:
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
loc_02056528:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
loc_02056540:
    mvn r0, #0x80000000
    bx lr
loc_02056548:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
loc_02056554:
    mvn r0, #0x80000000
    bx lr
}
