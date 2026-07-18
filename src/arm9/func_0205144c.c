// addr 0x0205144c size 0x10

typedef struct {
    unsigned char pad[0x20];
    int field_20;
} Unk_02094780;

extern Unk_02094780 data_02094780;

void func_0205144c(int v) {
    data_02094780.field_20 = v;
}
