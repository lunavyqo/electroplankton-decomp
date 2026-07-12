// addr 0x02001210 size 0x88

typedef struct {
    unsigned short cur;
    unsigned short trg;
    unsigned short rel;
    unsigned short prev;
} PadStatus;

extern volatile PadStatus data_02065c88;

void func_02001298(void);

void func_02001210(void) {
    int keys;
    int mask;

    mask = 0x2fff;
    data_02065c88.prev = data_02065c88.cur;
    keys = *(unsigned short *)0x04000130 | *(unsigned short *)0x027fffa8;
    keys = (keys ^ mask) & mask;
    data_02065c88.cur = keys;
    data_02065c88.trg = data_02065c88.cur & (data_02065c88.cur ^ data_02065c88.prev);
    data_02065c88.rel = data_02065c88.prev & (data_02065c88.prev ^ data_02065c88.cur);
    func_02001298();
}
