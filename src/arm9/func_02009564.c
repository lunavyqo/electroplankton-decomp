// addr 0x02009564 size 0x10

typedef struct {
    unsigned char pad[0x2c];
    int field_2c;
} Unk_0208938c_2c;

extern Unk_0208938c_2c data_0208938c;

int func_02009564(void) {
    return data_0208938c.field_2c;
}
