// addr 0x020013c8 size 0x12c

typedef struct {
    unsigned short cur;
    unsigned short trg;
    unsigned short rel;
    unsigned short prev;
    unsigned short x;
    unsigned short y;
} TouchStatus;

typedef struct {
    unsigned short x;
    unsigned short y;
} Point;

extern volatile TouchStatus data_02065cfc;

void func_0204fc54(void);
int func_0204fbfc(void *req);
void func_0204f85c(void *out, void *req);

void func_020013c8(void) {
    unsigned char req[8];
    unsigned short sample[4];
    unsigned short v;
    unsigned short c;
    volatile TouchStatus *tp;

    do {
        func_0204fc54();
    } while (func_0204fbfc(req) != 0);

    func_0204f85c(sample, req);

    if (sample[3] == 0 || sample[2] == 0) {
        tp = &data_02065cfc;
        c = tp->cur;
        v = sample[2];
        tp->prev = c;
        tp->cur = v;
        tp->trg = tp->cur & (tp->cur ^ tp->prev);
        tp->rel = tp->prev & (tp->prev ^ tp->cur);
        if (v != 0) {
            *(Point *)&tp->x = *(Point *)&sample[0];
        }
    } else {
        tp = &data_02065cfc;
        if (tp->cur != 0) {
            tp->prev = tp->cur;
            tp->trg = tp->cur & (tp->cur ^ tp->prev);
            tp->rel = tp->prev & (tp->prev ^ tp->cur);
        } else {
            tp->rel = 0;
            tp->trg = tp->rel;
            tp->cur = tp->trg;
            tp->prev = tp->cur;
        }
    }
}
