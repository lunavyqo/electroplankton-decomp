// addr 0x02024b4c size 0x8c8
// Mode-based plankton position init (double FX path + table FX paths)

typedef signed int s32;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long long s64;

typedef struct Child {
    s32 x;          /* 0x00 */
    s32 y;          /* 0x04 */
    char pad08[4];
    s32 x_tgt;      /* 0x0c */
    s32 y_tgt;      /* 0x10 */
    char pad14[0x1c];
    u8 flag30;      /* 0x30 */
    u8 flag31;      /* 0x31 */
    u16 field32;    /* 0x32 */
    u16 field34;    /* 0x34 */
    u16 field36;    /* 0x36 */
    s32 field38;    /* 0x38 */
    s32 field3c;    /* 0x3c */
} Child;

typedef struct Outer {
    char pad00[0x34];
    Child *slots[0x23]; /* 0x34 */
    char padC0[0x18];
    unsigned char mode; /* 0xd8 */
} Outer;

extern Outer *data_02090f1c;
extern s16 data_0205872c[];

s32 func_020024e4(s32 a, s32 b);
u16 func_02002528(s32 a, s32 b);

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void func_02024b4c(void) {
    /* reverse decl: last long-lived -> lower callee-saved (try sl-first for FX temp) */
    s32 ytmp;
    Child *ch;
    s32 vy;
    s32 vx;
    s32 t;
    s32 idx;
    double y;
    double x;
    double tmp;
    u16 i;
    Outer *outer;
    unsigned char mode;

    outer = data_02090f1c;
    mode = outer->mode;

    switch (mode) {
    case 0:
        i = 0;
        do {
            x = 1.142 * (double)((int)i % 7) + (-3.5);
            if (x > 0.0) {
                tmp = 4096.0 * x + 0.5;
            } else {
                tmp = 4096.0 * x - 0.5;
            }
            vx = (s32)tmp;
            data_02090f1c->slots[i]->x_tgt = vx;
            ch = data_02090f1c->slots[i];
            ch->x = ch->x_tgt;

            y = 2.5 - 1.25 * (double)((int)i / 7);
            if (y > 0.0) {
                tmp = 4096.0 * y + 0.5;
            } else {
                tmp = 4096.0 * y - 0.5;
            }
            vy = (s32)tmp;
            data_02090f1c->slots[i]->y_tgt = vy;
            ch = data_02090f1c->slots[i];
            ch->y = ch->y_tgt;

            data_02090f1c->slots[i]->field38 = func_020024e4(0x13f, 0x27f);
            ch = data_02090f1c->slots[i];
            ch->field3c = ch->field38;
            data_02090f1c->slots[i]->flag31 = 0;
            data_02090f1c->slots[i]->flag30 = 0;
            data_02090f1c->slots[i]->field32 = 0;
            data_02090f1c->slots[i]->field34 = func_02002528(0, 0xffff);
            data_02090f1c->slots[i]->field36 = func_02002528(0x2d8, 0x666);

            i = i + 1;
        } while (i < 0x23);
        break;

    case 1:
        i = 0;
        do {
            t = (s32)i * 0xfff0;
            idx = (t / 23) >> 4;

            vx = FX_MUL((s32)data_0205872c[idx * 2], 0x2666);
            data_02090f1c->slots[i]->x_tgt = vx;
            ch = data_02090f1c->slots[i];
            ch->x = ch->x_tgt;

            ytmp = FX_MUL((s32)data_0205872c[idx * 2 + 1], 0x2666);
            vy = FX_MUL(ytmp, -0x1000);
            data_02090f1c->slots[i]->y_tgt = vy;
            ch = data_02090f1c->slots[i];
            ch->y = ch->y_tgt;

            data_02090f1c->slots[i]->field38 = func_020024e4(0x13f, 0x27f);
            ch = data_02090f1c->slots[i];
            ch->field3c = ch->field38;
            data_02090f1c->slots[i]->flag31 = 0;
            data_02090f1c->slots[i]->flag30 = 0;
            data_02090f1c->slots[i]->field32 = 0;
            data_02090f1c->slots[i]->field34 = func_02002528(0, 0xffff);
            data_02090f1c->slots[i]->field36 = func_02002528(0x2d8, 0x666);

            i = i + 1;
        } while (i < 0x17);

        i = 0;
        do {
            idx = (((s32)i * 0xfff0) / 12) >> 4;

            vx = FX_MUL((s32)data_0205872c[idx * 2], 0x1333);
            data_02090f1c->slots[i + 0x17]->x_tgt = vx;
            ch = data_02090f1c->slots[i + 0x17];
            ch->x = ch->x_tgt;

            ytmp = FX_MUL((s32)data_0205872c[idx * 2 + 1], 0x1333);
            vy = FX_MUL(ytmp, -0x1000);
            data_02090f1c->slots[i + 0x17]->y_tgt = vy;
            ch = data_02090f1c->slots[i + 0x17];
            ch->y = ch->y_tgt;

            t = func_020024e4(0x13f, 0x27f);
            data_02090f1c->slots[i + 0x17]->field38 = FX_MUL(t, 0x99a);
            ch = data_02090f1c->slots[i + 0x17];
            ch->field3c = ch->field38;
            data_02090f1c->slots[i + 0x17]->flag31 = 0;
            data_02090f1c->slots[i + 0x17]->flag30 = 0;
            data_02090f1c->slots[i + 0x17]->field32 = 0;
            data_02090f1c->slots[i + 0x17]->field34 = func_02002528(0, 0xffff);
            data_02090f1c->slots[i + 0x17]->field36 = func_02002528(0x2d8, 0x666);

            i = i + 1;
        } while ((int)i < 12);
        break;

    case 2:
        i = 0;
        do {
            t = (s32)i * 0xfff0;
            idx = (t / 35) >> 4;

            vx = FX_MUL((s32)data_0205872c[idx * 2], 0x3333);
            data_02090f1c->slots[i]->x_tgt = vx;
            ch = data_02090f1c->slots[i];
            ch->x = ch->x_tgt;

            ytmp = FX_MUL((s32)data_0205872c[idx * 2 + 1], 0x2666);
            vy = FX_MUL(ytmp, -0x1000);
            data_02090f1c->slots[i]->y_tgt = vy;
            ch = data_02090f1c->slots[i];
            ch->y = ch->y_tgt;

            data_02090f1c->slots[i]->field38 = func_020024e4(0x13f, 0x27f);
            ch = data_02090f1c->slots[i];
            ch->field3c = ch->field38;
            data_02090f1c->slots[i]->flag31 = 0;
            data_02090f1c->slots[i]->flag30 = 0;

            i = i + 1;
        } while (i < 0x23);
        break;

    default:
        break;
    }
}
