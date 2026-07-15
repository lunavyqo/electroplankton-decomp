// addr 0x0205655c size 0x8
// float qNaN constant return (0x7fffffff) (MWCC soft-float runtime)
asm void func_0205655c()
{
    mvn r0, #0x80000000
    bx lr
}
