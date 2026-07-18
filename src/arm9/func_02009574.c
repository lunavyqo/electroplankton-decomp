// addr 0x02009574 size 0x10

typedef struct {
    unsigned char pad[0x10];
    int field_10;
} Unk_0208938c_10;

extern Unk_0208938c_10 data_0208938c;

int func_02009574(void) {
    return data_0208938c.field_10;
}
