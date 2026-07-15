// addr 0x02052eac size 0x30
// scalbn-like: ldexp(frexp(x, &e), e + n)

double func_020551bc(double x, int *eptr);
double func_0205527c(double x, int n);

double func_02052eac(double x, int n)
{
    int e;
    x = func_020551bc(x, &e);
    e = e + n;
    return func_0205527c(x, e);
}
