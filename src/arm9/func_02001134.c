// addr 0x02001134 size 0x94

typedef struct {
    unsigned short mask;
    unsigned short _pad;
    int *table;
    int index;
    int timer;
} KeySlot;

extern int data_02065c90[5];
extern KeySlot data_02065ca4[5];

void func_02001134(unsigned short mask, int *table) {
    int i;
    int zero;

    zero = 0;
loop:
    i = zero;
    while (1) {
        if (data_02065c90[i] == 0) {
            data_02065ca4[i].mask = mask;
            data_02065ca4[i].table = table;
            data_02065ca4[i].index = zero;
            data_02065ca4[i].timer = zero;
            data_02065c90[i] = 1;
            return;
        }
        i++;
        if (i >= 5) {
            data_02065c90[4] = zero;
            goto loop;
        }
    }
}
