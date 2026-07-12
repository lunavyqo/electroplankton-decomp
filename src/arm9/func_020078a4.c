// Table search + linear interpolate
// addr 0x020078a4 size 0x80

extern unsigned short data_0205862c[]; // halfword table

// func_020091d4(x, y0, y1, x0, x1) - linear interpolation
// Signature from disasm: r0=x, r1=table[i-1], r2=table[i], r3=x0, [sp]=x1
int func_020091d4(int x, int y0, int y1, int x0, int x1);

int func_020078a4(int x) {
    int i;
    int x1;
    int x0;
    int y0, y1;

    if (x == 0) {
        return 0;
    }

    for (i = 1; i < 0x7e; i++) {
        if (x < data_0205862c[i]) {
            break;
        }
    }

    x1 = (i << 8) + 0x80;
    x0 = ((i - 1) << 8) + 0x80;
    y0 = data_0205862c[i - 1];
    y1 = data_0205862c[i];
    return func_020091d4(x, y0, y1, x0, x1);
}
