// addr 0x0204aeac size 0x14 — zero u16 + two u32 fields
typedef struct {
    unsigned short a;
    unsigned short pad;
    unsigned int b;
    unsigned int c;
} S_0204aeac;

void func_0204aeac(S_0204aeac *p) {
    p->a = 0;
    p->b = 0;
    p->c = 0;
}
