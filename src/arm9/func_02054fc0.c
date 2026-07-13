// addr 0x02054fc0 size 0x24
// fabs (double) — clear sign bit of high word.

double func_02054fc0(double x)
{
    unsigned *p = (unsigned *)&x;
    p[1] &= ~0x80000000u;
    return x;
}
