// addr 0x0200625c size 0x2d8
// NONMATCHING: pure-C structural draft (div=182)

typedef struct {
    int pad00;
    int field04;
    int slot8[5];
    int slot1c[5];
    int slot30[5];
    unsigned char field44;
    signed char field45;
    char pad46[2];
    int field48;
} Obj;

extern Obj *data_0206f658;
extern unsigned char data_020585f0[];
extern unsigned char data_020585fc[];

void func_02043124(void *p, int a);
void func_02002654(void *p, int a, int b, int c, int d, int e);
void func_02042ff4(void *p, int a);

static int compute_vol(int d) {
    int t = (0x7f - (d << 4)) * 0x64;
    return t / 100;
}

void func_0200625c(int a, int mode, unsigned int ch, int d) {
    int idx = a;
    Obj *obj;
    int note;
    int vol;
    int i;
    unsigned char f44;

    while (idx >= 5) {
        idx -= 5;
    }

    obj = data_0206f658;
    f44 = obj->field44;
    /* ldrb from (data_020585f0 + f44*3 + mode) when mode is small int */
    note = idx + data_020585f0[f44 * 3 + mode];

    if (mode == 0) {
        func_02043124(&obj->slot8[idx], 0);
        vol = compute_vol(d);
        func_02002654(&data_0206f658->slot8[idx], 9, note, 0x3c, vol, 0);
        return;
    }
    if (mode == 1) {
        func_02043124(&obj->slot1c[idx], 0);
        vol = compute_vol(d);
        func_02002654(&data_0206f658->slot1c[idx], 9, note, 0x3c, vol, 0);
        return;
    }

    while (ch >= 8) {
        ch = (ch - 8) & 0xff;
    }

    func_02043124(&obj->slot30[idx], 0);
    {
        int off = idx * 4;
        Obj *o = data_0206f658;
        f44 = o->field44;
        if (f44 == 2 && idx == 2) {
            if (ch == 0 || ch == 3 || ch == 4 || ch == 7) {
                vol = compute_vol(d);
                func_02002654(
                    (char *)&o->slot30[0] + off,
                    9,
                    note,
                    data_020585fc[f44 * 8 + ch],
                    vol,
                    0
                );
            } else {
                vol = compute_vol(d);
                func_02002654(
                    (char *)&o->slot30[0] + off,
                    9,
                    note + 3,
                    data_020585fc[f44 * 8 + ch],
                    vol,
                    0
                );
            }
        } else {
            vol = compute_vol(d);
            func_02002654(
                (char *)&o->slot30[0] + off,
                9,
                note,
                data_020585fc[f44 * 8 + ch],
                vol,
                0
            );
        }
        {
            Obj *o2 = data_0206f658;
            func_02042ff4((char *)&o2->slot30[0] + off, o2->field48);
        }
    }
}
