// addr 0x02055560 size 0x174
// sin (double)

double func_0205362c(double x, double y); /* __kernel_cos */
double func_020545d0(double x, double y, int iy); /* __kernel_sin */
int func_02052edc(double x, double *y); /* __ieee754_rem_pio2 */
double func_02055f8c(double x, double y); /* _d_sub */

double func_02055560(double x)
{
    double y[2], z = 0.0;
    int n, ix;

    ix = ((int *)&x)[1];
    ix &= 0x7fffffff;
    if (ix <= 0x3fe921fb) {
        return func_020545d0(x, z, 0);
    } else if (ix >= 0x7ff00000) {
        return func_02055f8c(x, x);
    } else {
        n = func_02052edc(x, y);
        switch (n & 3) {
        case 0:
            return func_020545d0(y[0], y[1], 1);
        case 1:
            return func_0205362c(y[0], y[1]);
        case 2:
            return func_02055f8c(0.0, func_020545d0(y[0], y[1], 1));
        default:
            return func_02055f8c(0.0, func_0205362c(y[0], y[1]));
        }
    }
}
