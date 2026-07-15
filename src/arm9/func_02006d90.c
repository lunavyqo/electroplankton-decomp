// addr 0x02006d90 size 0x680
// NONMATCHING: pure-C partial reconstruction (div=416)

typedef struct {
    unsigned short field00;
    unsigned char field02;
    unsigned char field03;
} Slot4;

typedef struct {
    char pad[0xa7e];
    unsigned char idx;
} G_020708a4;

extern G_020708a4 data_020708a4;
extern Slot4 data_02070eac[]; /* array by idx */
extern unsigned char data_0206feac[];
extern int data_0206f768;
extern int data_0206f760;
extern unsigned char data_020712b0[];
extern unsigned short data_020712a4[]; /* +8,+a stores */

int func_02007924(int a, void *b, int c, int d, int e, int f, int g, void *h);
int func_020078a4(void);
int func_0200777c(int a, void *b, int c, int d, int e, int f, int g, void *h);
void func_020074e8(void);
void func_02007410(void);
int func_020091a4(int a, int b, int c, int d, int e);
void func_02009290(void);
void func_0200742c(void);
void func_02009328(void);

void func_02006d90(void) {
    unsigned char idx = data_020708a4.idx;
    Slot4 *slot = &data_02070eac[idx];
    int r;
    int i;
    int found;
    int walk;
    unsigned char stack_pad[0xfc];
    Slot4 local;

    (void)stack_pad;

    r = func_02007924(
        0x80,
        data_0206feac,
        0x7d0,
        0,
        0x19,
        0x78,
        0x28,
        /* more stack args 0x14, 0xf, &local */
        &local
    );
    /* actual signature needs 0x14, 0xf on stack — approximate via locals */
    data_0206f768 = data_0206f768 + 1;

    if (r >= 0x50) {
        local.field00 = (unsigned short)func_020078a4();
        {
            int v = data_0206f760;
            if (v > 0xff) {
                v = 0xff;
            }
            local.field02 = (unsigned char)v;
        }
        local.field03 = (unsigned char)func_0200777c(
            0x80, data_0206feac, 0x7d0, 0x78, 0x28, 8, 8, data_020712b0
        );
    } else {
        local.field00 = 0;
        local.field02 = 0;
        local.field03 = 0;
    }

    *slot = local;
    data_020712a4[4] = local.field00; /* +8 as halfword index? */
    /* target: strh to [r1,#8] and [r1,#0xa] on data_020712a4 */
    {
        unsigned short *p = (unsigned short *)((char *)&data_020712a4 + 0); 
        /* use byte offsets */
    }

    /* walk back through slots looking for zero halfword at +0 */
    found = 1;
    walk = idx;
    for (i = 0; i < 0x14; i++) {
        if (data_02070eac[walk].field00 != 0) {
            found = 0;
            break;
        }
        walk = walk - 1;
        if (walk < 0) {
            walk += 0x100;
        }
    }
    {
        unsigned short h = data_02070eac[walk].field00;
        if (h == 0) {
            found = 0;
        }
        if (found == 0) {
            return;
        }
    }

    /* remainder of function: matrix copies, more helpers — stub for draft */
    (void)i;
}
