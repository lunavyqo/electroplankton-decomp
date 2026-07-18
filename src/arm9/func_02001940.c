// addr 0x02001940 size 0x64

typedef struct {
    int field00;
    int field04;
    int pad08;
    int pad0c;
    int pad10;
    int pad14;
} Slot_02001940;

extern int data_02065d08;
extern int data_02065d0c;
extern Slot_02001940 data_02065d88[];
extern Slot_02001940 data_02066988[];

void func_02001940(void) {
    int i;
    Slot_02001940 *p;
    int neg1;

    data_02065d08 = 0;
    data_02065d0c = 0;
    neg1 = -1;
    p = data_02065d88;
    i = 0;
    do {
        i++;
        p->field04 = neg1;
        p++;
    } while (i < 0x80);

    p = data_02066988;
    i = 0;
    neg1 = -1;
    do {
        i++;
        p->field04 = neg1;
        p++;
    } while (i < 0x80);
}
