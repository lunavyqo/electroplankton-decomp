// addr 0x02050250 size 0x10

typedef struct {
    unsigned char pad[0xc];
    int field_0c;
} Unk_02094704;

extern Unk_02094704 data_02094704;

void func_02050250(int v) {
    data_02094704.field_0c = v;
}
