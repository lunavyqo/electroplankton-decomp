// addr 0x02009a58 size 0x1c — if field_28==0 load +0x50 else +0x8c
typedef struct {
    unsigned char pad[0x28];
    int field_28;
    unsigned char pad2[0x50 - 0x2c];
    int field_50;
    unsigned char pad3[0x8c - 0x54];
    int field_8c;
} Unk_0208938c_mix;

extern Unk_0208938c_mix data_0208938c;

int func_02009a58(void) {
    if (data_0208938c.field_28 == 0) {
        return data_0208938c.field_50;
    } else {
        return data_0208938c.field_8c;
    }
}
