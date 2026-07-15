// addr 0x02039a20 size 0x28

typedef struct {
    int pad0[3];
    int field_c;
    int pad1;
    int field_14;
    int field_18;
    int pad2[2];
} Slot; // 0x24 bytes

void func_02039a20(void *base) {
    unsigned int i;
    int zero = 0;
    Slot *p = (Slot *)base;
    for (i = 0; i < 10u; i++) {
        p->field_c = zero;
        p->field_14 = zero;
        p->field_18 = zero;
        p++;
    }
}
