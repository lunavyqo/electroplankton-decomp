// addr 0x0205527c size 0x2e4
// ldexp — x * 2^n


static const double two54 = 1.8014398509481984e+16;
static const double twom54 = 5.551115123125783e-17;
static const double huge = 1.0e+300;
static const double tiny = 1.0e-300;
double func_02054e28(double, double);

double func_0205527c(double x, int n)
{
    int hx, lx, klass, k;
    double z = x;

    lx = ((int *)&z)[0];
    hx = ((int *)&z)[1];

    switch (hx & 0x7ff00000) {
    case 0x7ff00000:
        if ((hx & 0xfffff) || lx)
            klass = 1;
        else
            klass = 2;
        break;
    case 0:
        if ((hx & 0xfffff) || lx)
            klass = 5;
        else
            klass = 3;
        break;
    default:
        klass = 4;
        break;
    }

    if (klass > 2) {
        if (!(0.0 == z))
            goto body;
    }
    return z;

body:
    lx = ((int *)&x)[0];
    hx = ((int *)&x)[1];
    k = (hx & 0x7ff00000) >> 20;
    if (k == 0) {
        if ((lx | (hx & 0x7fffffff)) == 0)
            return x;
        x *= two54;
        hx = ((int *)&x)[1];
        k = ((hx & 0x7ff00000) >> 20) - 54;
        if (n < -50000)
            return tiny * x;
    }
    if (k == 0x7ff)
        return x + x;
    k = k + n;
    if (k > 0x7fe)
        return huge * func_02054e28(huge, x);
    if (k > 0) {
        ((int *)&x)[1] = (hx & 0x800fffff) | (k << 20);
        return x;
    }
    if (k <= -54) {
        if (n > 50000)
            return huge * func_02054e28(huge, x);
        else
            return tiny * func_02054e28(tiny, x);
    }
    k += 54;
    ((int *)&x)[1] = (hx & 0x800fffff) | (k << 20);
    return x * twom54;
}
