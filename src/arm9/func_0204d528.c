// addr 0x0204d528 size 0x20 — zero two-word struct via local assign
typedef struct {
    unsigned int a;
    unsigned int b;
} Pair;

void func_0204d528(Pair *p) {
    Pair z;
    z.a = 0;
    z.b = 0;
    *p = z;
}
