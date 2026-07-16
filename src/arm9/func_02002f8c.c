// NONMATCHING: node stride/cast and middle-loop s16 saturating casts (div~70 when size-matched)
// addr 0x02002f8c size 0x1e4

typedef signed short s16;

void func_02002f8c(s16 *a, s16 *b, unsigned int len, int flag, int *nodes) {
    int n;
    int i;
    int d;
    int t;
    s16 tmp[2];
    int ip;

    if (flag != 0) {
        return;
    }

    n = (int)(len >> 1);

    for (i = 0; i < 2; i++) {
        d = (int)a[n - 2 + i] - (int)b[n - 2 + i];
        if (d < -0x8000) {
            d = -0x8000;
        } else if (d >= 0x8000) {
            d = 0x7fff;
        }
        tmp[i] = (s16)d;
    }

    ip = n - 1;
    if (ip >= 2) {
        do {
            d = (int)a[ip - 2] - (int)b[ip - 2];
            if (d >= 0) {
                t = d + (int)a[ip];
                if (t < 0x8000) {
                    t = (s16)t;
                } else {
                    t = 0x7fff;
                }
                a[ip] = (s16)t;
                t = (int)b[ip] - d;
                if (t >= -0x8000) {
                    t = (s16)t;
                } else {
                    t = -0x8000;
                }
                b[ip] = (s16)t;
            } else {
                t = d + (int)a[ip];
                if (t >= -0x8000) {
                    t = (s16)t;
                } else {
                    t = -0x8000;
                }
                a[ip] = (s16)t;
                t = (int)b[ip] - d;
                if (t < 0x8000) {
                    t = (s16)t;
                } else {
                    t = 0x7fff;
                }
                b[ip] = (s16)t;
            }
            ip = ip - 1;
        } while (ip >= 2);
    }

    i = 1;
    do {
        t = (int)a[i] + nodes[i + 3];
        if (t < -0x8000) {
            t = -0x8000;
        } else if (t >= 0x8000) {
            t = 0x7fff;
        }
        a[i] = (s16)t;

        t = (int)b[i] - nodes[i + 3];
        if (t < -0x8000) {
            t = -0x8000;
        } else if (t >= 0x8000) {
            t = 0x7fff;
        }
        b[i] = (s16)t;
        i = i - 1;
    } while (i >= 0);

    for (i = 0; i < 2; i++) {
        nodes[i + 3] = tmp[i];
    }
}
