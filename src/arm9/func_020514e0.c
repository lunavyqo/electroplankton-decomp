// NONMATCHING: large IPC/FIFO handler — pure C draft (div=356, size 1336/1424)
// addr 0x020514e0 size 0x590

typedef struct {
    int field00;   // +0x00
    void (*cb)(int, int, int); // +0x04  (stored/cleared as int)
    int *field08;  // +0x08
    int *field0c;  // +0x0c
    int field10;   // +0x10
    int field14;   // +0x14 state
    int field18;   // +0x18 busy flag
    void (*field1c)(void); // +0x1c
} State;

State DAT_02094780;
unsigned int DAT_027ffde8;
unsigned int DAT_027ffdec;
unsigned short DAT_027ffdea;

int func_0205145c(unsigned int v);
int func_02051bec(void);

void func_020514e0(int unused, int msg, int flag) {
    State *p0;
    State *p2;
    void (*cb)(int, int, int);
    int r5;
    unsigned int cmd;
    unsigned int lo;
    int *out;
    unsigned int hw;
    unsigned short h;
    int f18;
    int *p;
    int arg;

    if (flag != 0) {
        p0 = &DAT_02094780;
        p2 = &DAT_02094780;
        f18 = p0->field18;
        cb = p2->cb;
        if (f18 != 0) {
            p0->field18 = 0;
        }
        if (p0->field00 != 0) {
            p0->field00 = 0;
        }
        if (cb == 0) {
            return;
        }
        arg = p2->field10;
        p2->cb = (void (*)(int, int, int))0;
        cb(6, arg, 0);
        return;
    }

    /* extract command byte and low byte from msg (still in r1 at entry to this path) */
    {
        unsigned int tmp = (unsigned int)msg & 0x7f00;
        cmd = tmp >> 8;
        cmd = (unsigned char)cmd;
        lo = (unsigned int)msg & 0xff;
    }

    p0 = &DAT_02094780;

    if (cmd == 0x30) {
        if (p0->field1c == 0) {
            return;
        }
        p0->field1c();
        return;
    }

    /* lo==0 path first so MWCC emits field14 jump table before lo table */
    if (lo == 0) {
        r5 = 0;
        if ((unsigned int)p0->field14 > 0xf) {
            p0->field18 = 0;
            r5 = 4;
        } else {
            switch (p0->field14) {
            case 0:
                out = p0->field08;
                out[0] = func_0205145c(*(unsigned char *)&DAT_027ffde8);
                hw = DAT_027ffde8;
                out[1] = func_0205145c((hw << 0x13) >> 0x1b);
                hw = DAT_027ffde8;
                out[2] = func_0205145c((hw << 0xa) >> 0x1a);
                hw = DAT_027ffde8;
                out[3] = (hw << 5) >> 0x1d;
                break;

            case 1:
                out = p0->field08;
                hw = DAT_027ffdec;
                out[0] = func_0205145c((hw << 0x1a) >> 0x1a);
                hw = DAT_027ffdec;
                out[1] = func_0205145c((hw << 0x11) >> 0x19);
                hw = DAT_027ffdec;
                out[2] = func_0205145c((hw << 9) >> 0x19);
                break;

            case 2:
                out = p0->field08;
                hw = DAT_027ffde8;
                out[0] = func_0205145c(hw & 0xff);
                hw = DAT_027ffde8;
                out[1] = func_0205145c((hw << 0x13) >> 0x1b);
                hw = DAT_027ffde8;
                out[2] = func_0205145c((hw << 0xa) >> 0x1a);
                hw = DAT_027ffde8;
                out[3] = (hw << 5) >> 0x1d;
                out = p0->field0c;
                hw = DAT_027ffdec;
                out[0] = func_0205145c((hw << 0x1a) >> 0x1a);
                hw = DAT_027ffdec;
                out[1] = func_0205145c((hw << 0x11) >> 0x19);
                hw = DAT_027ffdec;
                out[2] = func_0205145c((hw << 9) >> 0x19);
                break;

            case 3:
            case 4:
            case 5:
                break;

            case 6:
                p = p0->field08;
                h = DAT_027ffdea;
                if (((h << 0x1c) >> 0x1c) == 4) {
                    p[0] = 1;
                } else {
                    p[0] = 0; /* r5 is 0 */
                }
                break;

            case 7:
                p = p0->field08;
                h = DAT_027ffdea;
                if (((h << 0x19) >> 0x1f) != 0) {
                    p[0] = 1;
                } else {
                    p[0] = 0;
                }
                break;

            case 8:
                out = p0->field08;
                hw = DAT_027ffdec;
                out[0] = (hw << 0x1d) >> 0x1d;
                hw = DAT_027ffdec;
                out[1] = func_0205145c((hw << 0x12) >> 0x1a);
                hw = DAT_027ffdec;
                out[2] = func_0205145c((hw << 9) >> 0x19);
                out[3] = 0;
                hw = DAT_027ffdec;
                if (((hw << 0x18) >> 0x1f) != 0) {
                    out[3] = out[3] + 1;
                }
                hw = DAT_027ffdec;
                if (((hw << 0x10) >> 0x1f) != 0) {
                    out[3] = out[3] + 2;
                }
                hw = DAT_027ffdec;
                if (((hw << 8) >> 0x1f) != 0) {
                    out[3] = out[3] + 4;
                }
                break;

            case 9:
                f18 = p0->field18;
                if (f18 != 0) {
                    p0->field18 = 0;
                    break;
                }
                if (p0->field08[0] == 1) {
                    h = DAT_027ffdea;
                    if (((h << 0x1c) >> 0x1c) == 4) {
                        break;
                    }
                    p0->field18 = f18 + 1;
                    DAT_027ffdea = (unsigned short)((h & ~0xf) | 4);
                    if (func_02051bec() == 0) {
                        p0->field18 = 0;
                        r5 = 3;
                    }
                } else {
                    h = DAT_027ffdea;
                    if (((h << 0x1c) >> 0x1c) == 0) {
                        break;
                    }
                    p0->field18 = f18 + 1;
                    DAT_027ffdea = (unsigned short)(h & ~0xf);
                    if (func_02051bec() == 0) {
                        p0->field18 = 0;
                        r5 = 3;
                    }
                }
                break;

            case 10:
                f18 = p0->field18;
                if (f18 != 0) {
                    p0->field18 = 0;
                    break;
                }
                if (p0->field08[0] == 1) {
                    h = DAT_027ffdea;
                    if (((h << 0x19) >> 0x1f) != 0) {
                        break;
                    }
                    p0->field18 = f18 + 1;
                    DAT_027ffdea = (unsigned short)(h | 0x40);
                    if (func_02051bec() == 0) {
                        p0->field18 = 0;
                        r5 = 3;
                    }
                } else {
                    h = DAT_027ffdea;
                    if (((h << 0x19) >> 0x1f) == 0) {
                        break;
                    }
                    p0->field18 = f18 + 1;
                    DAT_027ffdea = (unsigned short)(h & ~0x40);
                    if (func_02051bec() == 0) {
                        p0->field18 = 0;
                        r5 = 3;
                    }
                }
                break;

            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                break;

            default:
                p0->field18 = 0;
                r5 = 4;
                break;
            }
        }
    } else {
        /* lo != 0: clear busy and map lo -> result code */
        p0->field18 = 0;
        if (lo <= 4) {
            switch (lo) {
            case 0:
                r5 = 6;
                break;
            case 1:
                r5 = 4;
                break;
            case 2:
                r5 = 5;
                break;
            case 3:
                r5 = 1;
                break;
            default:
                r5 = 6;
                break;
            }
        } else {
            r5 = 6;
        }
    }

    /* epilogue @ 0x2051a00 */
    if (p0->field18 != 0) {
        return;
    }
    if (p0->field00 != 0) {
        p0->field00 = 0;
    }
    cb = p0->cb;
    if (cb == 0) {
        return;
    }
    {
        int arg = p0->field10;
        p0->cb = (void (*)(int, int, int))0;
        cb(r5, arg, 0);
    }
}
