// addr 0x02001728 size 0xa4

typedef struct {
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int pad14;
} Slot_02001728;

extern Slot_02001728 data_02065d88[];
extern int data_02065d0c;
extern Slot_02001728 data_02066988[];
extern int data_02065d08;

void func_02001728(int a, int type, int b, int c, int d) {
    unsigned i;
    int limit;
    Slot_02001728 *table;
    int *countp;
    Slot_02001728 *p;
    unsigned zero;

    if (type < 0xd) {
        limit = 0x80;
        table = data_02065d88;
        countp = &data_02065d0c;
    } else {
        limit = 0x80;
        table = data_02066988;
        countp = &data_02065d08;
    }
    i = 0;
    zero = 0;
    if ((unsigned)limit <= zero) {
        return;
    }
    p = table;
    do {
        if (p->field04 == -1) {
            table[i].field00 = a;
            table[i].field04 = type;
            table[i].field08 = b;
            table[i].field0c = c;
            table[i].field10 = d;
            (*countp)++;
            return;
        }
        i++;
        p++;
    } while (i < (unsigned)limit);
}
