// addr 0x0201ac00 size 0x64

typedef struct H12 {
    unsigned short w[12];
} H12;

extern H12 data_02062070;
extern H12 data_02062028;

void func_0201ac00(H12 *self) {
    self[0] = data_02062070;
    self[1] = data_02062028;
}
