// addr 0x02001298 size 0xf4

typedef struct {
    unsigned short cur;
    unsigned short trg;
    unsigned short rel;
    unsigned short prev;
} PadStatus;

typedef struct {
    unsigned short mask;
    unsigned short _pad;
    int *table;
    int index;
    int timer;
} KeySlot;

typedef struct {
    unsigned short cur;
    unsigned short trg;
    unsigned short rel;
} PadSample;

extern PadStatus data_02065c88;
extern int data_02065c90[];
extern KeySlot data_02065ca4[];

void func_020011ec(PadSample *dst);

void func_02001298(void) {
    PadSample sample;
    int i;
    unsigned short trg;
    unsigned short cur;
    int zero;
    int neg1;
    unsigned short mask;
    int val;

    func_020011ec(&sample);

    i = 0;
    trg = sample.trg;
    cur = sample.cur;
    zero = 0;
    neg1 = -1;

    while (i < 5) {
        if (data_02065c90[i] != 0) {
            mask = data_02065ca4[i].mask;
            if ((trg & mask) != 0) {
                data_02065ca4[i].index = zero;
                data_02065ca4[i].timer = data_02065ca4[i].table[data_02065ca4[i].index];
            } else if ((cur & mask) != 0) {
                data_02065ca4[i].timer = data_02065ca4[i].timer - 1;
                if (data_02065ca4[i].timer <= 0) {
                    data_02065c88.trg = (unsigned short)(data_02065c88.trg | data_02065ca4[i].mask);
                    val = data_02065ca4[i].table[data_02065ca4[i].index + 1];
                    if (val != neg1) {
                        data_02065ca4[i].index = data_02065ca4[i].index + 1;
                    }
                    data_02065ca4[i].timer = data_02065ca4[i].table[data_02065ca4[i].index];
                }
            }
        }
        i++;
    }
}
