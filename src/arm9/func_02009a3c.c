// addr 0x02009a3c size 0x1c — return data_0208938c.field_28 == 0
typedef struct {
    unsigned char pad[0x28];
    int field_28;
} Unk_0208938c_28;

extern Unk_0208938c_28 data_0208938c;

int func_02009a3c(void) {
    return data_0208938c.field_28 == 0;
}
