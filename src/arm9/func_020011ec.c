// addr 0x020011ec size 0x24

typedef struct {
    unsigned short cur;
    unsigned short trg;
    unsigned short rel;
} PadSample;

extern PadSample data_02065c88;

void func_020011ec(PadSample *dst) {
    *dst = data_02065c88;
}
