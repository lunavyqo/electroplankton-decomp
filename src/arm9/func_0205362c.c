// addr 0x0205362c size 0x33c
// __kernel_cos (fdlibm, original Sun form with qx)

static const double
one =  1.00000000000000000000e+00,
C1  =  4.16666666666666019037e-02,
C2  = -1.38888888888741095749e-03,
C3  =  2.48015872894767294178e-05,
C4  = -2.75573143513906633035e-07,
C5  =  2.08757232129817482790e-09,
C6  = -1.13596475577881948265e-11;

double func_0205362c(double x, double y)
{
    double a, hz, z, r, qx;
    int ix, hx;
    hx = ((int *)&x)[1];
    ix = hx & 0x7fffffff;
    if (ix < 0x3e400000) {
        if ((int)x == 0)
            return one;
    }
    z = x * x;
    r = z * (C1 + z * (C2 + z * (C3 + z * (C4 + z * (C5 + z * C6)))));
    if (ix < 0x3FD33333)
        return one - (0.5 * z - (z * r - x * y));
    else {
        if (ix > 0x3fe90000) {
            qx = 0.28125;
        } else {
            ((int *)&qx)[1] = ix - 0x00200000;
            ((int *)&qx)[0] = 0;
        }
        hz = 0.5 * z - qx;
        a = one - qx;
        return a - (hz - (z * r - x * y));
    }
}
