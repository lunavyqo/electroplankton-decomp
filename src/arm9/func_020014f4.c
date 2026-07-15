// addr 0x020014f4 size 0x64
// Touch/input reset path: call helpers then clear TouchStatus fields.
//
// NONMATCHING: (div=12) equivalent C exists; mwcc inlining/regalloc diverges from
// the expanded store chain in the ROM (was previously banked as asm paste).

typedef struct {
    unsigned short cur, trg, rel, prev;
    short x, y;
} TouchStatus;

extern void func_0204d710(void);
extern void func_0204fee8(void);
extern void func_0204fe3c(void *);
extern void func_0204fcf4(void *);
extern unsigned char data_02065cf4;
extern volatile TouchStatus data_02065cfc;

void func_020014f4(void) {
    func_0204d710();
    func_0204fee8();
    func_0204fe3c(&data_02065cf4);
    func_0204fcf4(&data_02065cf4);
    {
        volatile TouchStatus *tp = &data_02065cfc;
        tp->prev = 0;
        tp->rel = tp->prev;
        tp->trg = tp->rel;
        tp->cur = tp->trg;
        tp->y = 0;
        tp->x = tp->y;
    }
}
