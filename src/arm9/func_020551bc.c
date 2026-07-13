
double func_020551bc(double x, int *eptr)
{
    int hx = ((int *)&x)[1];
    int lx = ((int *)&x)[0];
    int ix = hx & 0x7fffffff;
    *eptr = 0;
    if (ix >= 0x7ff00000 || ((ix | lx) == 0))
        return x;
    if (ix < 0x00100000) {
        x *= 1.8014398509481984e+16;
        hx = ((int *)&x)[1];
        ix = hx & 0x7fffffff;
        *eptr = -54;
    }
    *eptr += (ix >> 20) - 1022;
    ((int *)&x)[1] = (hx & 0x800fffff) | 0x3fe00000;
    return x;
}
