// addr 0x02054e28 size 0x28

double func_02054e28(double x, double y)
{
    int hx, hy;
    hx = ((int *)&x)[1];
    hy = ((int *)&y)[1];
    ((int *)&x)[1] = (hx & 0x7fffffff) | (hy & 0x80000000);
    return x;
}
