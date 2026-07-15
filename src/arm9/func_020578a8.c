// addr 0x020578a8 size 0xc
// double→int entry (unsigned path, r4=0) into 578bc (MWCC soft-float runtime)

void ext_020578bc(void);
asm void func_020578a8()
{
    stmdb sp!, {r4, r5, r6, r7, r11, r12, lr}
    mov r4, #0
    b ext_020578bc
}
