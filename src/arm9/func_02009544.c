// addr 0x02009544 size 0x10

typedef struct {
    unsigned char pad[0x1c];
    int field_1c;
} Unk_0208938c;

extern Unk_0208938c data_0208938c;

int func_02009544(void) {
    return data_0208938c.field_1c;
}
