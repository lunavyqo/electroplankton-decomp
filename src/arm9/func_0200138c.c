// addr 0x0200138c size 0x3c

typedef struct {
    unsigned short cur;
    unsigned short trg;
    unsigned short rel;
    unsigned short prev;
    unsigned short x;
    unsigned short y;
} TouchStatus;

extern TouchStatus data_02065cfc;

void func_0200138c(TouchStatus *dst) {
    *dst = data_02065cfc;
}
