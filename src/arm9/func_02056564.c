// addr 0x02056564 size 0x48
// Soft-float float ordered compare → 0/1/2/3 (eq/lt/gt/unord).
// Split NaN checks (target: movlo/bxlo after each cmp lim, rn, lsl #1).
//
// NONMATCHING: codegen wall — target uses bicmi/rsbmi + moveq/lt/gt (72B); (div=21)
// this C emits larger split compares without conditional-exec forms (div below).

int func_02056564(int a, int b) {
    unsigned lim = 0xFF000000u;
    if (lim < ((unsigned)a << 1)) {
        return 3;
    }
    if (lim < ((unsigned)b << 1)) {
        return 3;
    }
    if (a < 0) {
        a &= ~0x80000000;
        a = -a;
    }
    if (b < 0) {
        b &= ~0x80000000;
        b = -b;
    }
    if (a == b) {
        return 0;
    }
    if (a < b) {
        return 1;
    }
    return 2;
}
