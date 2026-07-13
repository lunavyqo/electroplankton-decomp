// addr 0x02058410 size 0x38
// Walk null-terminated function-pointer table (static ctors/dtors)

typedef void (*VoidFunc)(void);
extern VoidFunc data_0205d00c[];

asm void func_02058410(void)
{
    stmdb sp!, {r4, lr}
    ldr r4, =data_0205d00c
    b Lcheck
Lcall:
    blx r0
    add r4, r4, #4
Lcheck:
    cmp r4, #0
    ldmeqia sp!, {r4, lr}
    bxeq lr
    ldr r0, [r4]
    cmp r0, #0
    bne Lcall
    ldmia sp!, {r4, lr}
    bx lr
}
