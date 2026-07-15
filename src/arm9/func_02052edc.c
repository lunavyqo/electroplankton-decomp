// addr 0x02052edc size 0x750
// __ieee754_rem_pio2 (fdlibm)

extern const int two_over_pi[];
extern const int npio2_hw[];

static const double
zero = 0.0,
half = 0.5,
two24 = 1.67772160000000000000e+07,
invpio2 = 6.36619772367581382433e-01,
pio2_1 = 1.57079632673412561417e+00,
pio2_1t = 6.07710050650619224932e-11,
pio2_2 = 6.07710050630396597660e-11,
pio2_2t = 2.02226624879595063154e-21,
pio2_3 = 2.02226624871116645580e-21,
pio2_3t = 8.47842766036889956997e-32;

double func_02054fc0(double x);
int func_02053968(double *x, double *y, int e0, int nx, int prec, const int *ipio2);

int func_02052edc(double x, double *y)
{
    double z, w, t, r, fn;
    double tx[3];
    int i, j, n, ix, hx;
    int e0, nx;
    unsigned int low;

    hx = ((int *)&x)[1];
    ix = hx & 0x7fffffff;
    if (ix <= 0x3fe921fb) {
        y[0] = x;
        y[1] = 0.0;
        return 0;
    }
    if (ix < 0x4002d97c) {
        if (hx > 0) {
            z = x - pio2_1;
            if (ix != 0x3ff921fb) {
                y[0] = z - pio2_1t;
                y[1] = (z - y[0]) - pio2_1t;
            } else {
                z -= pio2_2;
                y[0] = z - pio2_2t;
                y[1] = (z - y[0]) - pio2_2t;
            }
            return 1;
        } else {
            z = x + pio2_1;
            if (ix != 0x3ff921fb) {
                y[0] = z + pio2_1t;
                y[1] = (z - y[0]) + pio2_1t;
            } else {
                z += pio2_2;
                y[0] = z + pio2_2t;
                y[1] = (z - y[0]) + pio2_2t;
            }
            return -1;
        }
    }
    if (ix <= 0x413921fb) {
        t = func_02054fc0(x);
        n = (int)(t * invpio2 + half);
        fn = (double)n;
        r = t - fn * pio2_1;
        w = fn * pio2_1t;
        if (n < 32 && ix != npio2_hw[n - 1]) {
            y[0] = r - w;
        } else {
            int high;
            j = ix >> 20;
            y[0] = r - w;
            high = ((int *)&y[0])[1];
            i = j - ((high >> 20) & 0x7ff);
            if (i > 16) {
                t = r;
                w = fn * pio2_2;
                r = t - w;
                w = fn * pio2_2t - ((t - r) - w);
                y[0] = r - w;
                high = ((int *)&y[0])[1];
                i = j - ((high >> 20) & 0x7ff);
                if (i > 49) {
                    t = r;
                    w = fn * pio2_3;
                    r = t - w;
                    w = fn * pio2_3t - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0) {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        } else
            return n;
    }
    if (ix >= 0x7ff00000) {
        y[0] = y[1] = x - x;
        return 0;
    }
    low = ((unsigned int *)&x)[0];
    e0 = (int)((ix >> 20) - 1046);
    ((unsigned int *)&z)[0] = low;
    ((unsigned int *)&z)[1] = ix - ((int)e0 << 20);
    for (i = 0; i < 2; i++) {
        tx[i] = (double)((int)z);
        z = (z - tx[i]) * two24;
    }
    tx[2] = z;
    nx = 3;
    while (tx[nx - 1] == zero)
        nx--;
    n = func_02053968(tx, y, e0, nx, 2, two_over_pi);
    if (hx < 0) {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}
