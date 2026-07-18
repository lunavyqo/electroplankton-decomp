// addr 0x0200185c size 0xb0

typedef struct {
    int field00;
    int field04;
    int pad08;
    int pad0c;
    int pad10;
    int pad14;
} Slot_0200185c; // 0x18

extern int data_02065d0c;
extern Slot_0200185c data_02065d88[];
extern void (*data_0205d05c[])(Slot_0200185c *);
extern void (*data_0205d020[])(Slot_0200185c *);

void func_0200185c(void) {
    int i;
    Slot_0200185c *p;

    if (data_02065d0c == 0) {
        return;
    }
    i = 0;
    p = data_02065d88;
    do {
        if (p->field04 != -1) {
            if (p->field00 == 1) {
                data_0205d020[p->field04](p);
            } else {
                data_0205d05c[p->field04](p);
            }
            p->field04 = -1;
            data_02065d0c--;
            if (data_02065d0c == 0) {
                return;
            }
        }
        i++;
        p++;
    } while (i < 0x80);
}
