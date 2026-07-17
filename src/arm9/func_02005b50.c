// addr 0x02005b50 size 0xd0

typedef struct {
    char pad[0x50];
    unsigned char field50;
} Obj;

extern Obj *data_0206f554;
extern int data_0205d254[];
extern int data_0205d268[];

void func_02002654(void *p, int a, int b, int c, int d, int e);

void func_02005b50(int a, int b, int mode) {
    Obj *base;
    int note;
    int vol_src;

    if (mode == 0) {
        return;
    }
    if (mode == 1) {
        base = data_0206f554;
        vol_src = data_0205d254[a];
        note = data_0205d268[a];
        func_02002654(
            (char *)base + a * 0xc + b * 4,
            8,
            base->field50 << 1,
            note + b * 0xc,
            0,
            vol_src
        );
        return;
    }
    base = data_0206f554;
    vol_src = data_0205d254[a];
    note = data_0205d268[a];
    func_02002654(
        (char *)base + a * 0xc + b * 4,
        8,
        (base->field50 << 1) + 1,
        note + b * 0xc,
        0,
        vol_src
    );
}
