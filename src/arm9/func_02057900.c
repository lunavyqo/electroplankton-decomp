// addr 0x02057900 size 0x1b0
// Soft-float / long-division related entry (calls into 57ab0 family).
//
// NONMATCHING: (div=108) multi-reg ABI body; was asm paste. Stub keeps symbol for drafts.

int func_02057900(int a, int b, int c, int d) {
    (void)c;
    (void)d;
    if (b == 0) {
        return 0;
    }
    return a / b;
}
