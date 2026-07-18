// addr 0x020017cc size 0x90

typedef struct {
    int field00;
    int field04;
    int pad08;
    int pad0c;
    int pad10;
    int pad14;
} Slot_020017cc; // 0x18

extern int data_02065d08;
extern Slot_020017cc data_02066988[];
extern void (*data_0205d05c[])(Slot_020017cc *);

void func_0204b7d4(void);

void func_020017cc(void) {
    int i;
    Slot_020017cc *p;

    if (data_02065d08 == 0) {
        return;
    }
    i = 0;
    p = data_02066988;
    do {
        if (p->field04 != -1) {
            if (p->field00 == 1) {
                func_0204b7d4();
            } else {
                data_0205d05c[p->field04](p);
            }
            p->field04 = -1;
            data_02065d08--;
            if (data_02065d08 == 0) {
                return;
            }
        }
        i++;
        p++;
    } while (i < 0x80);
}
