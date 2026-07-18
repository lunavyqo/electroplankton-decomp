// addr 0x02009700 size 0x10

typedef struct {
    unsigned char pad[0x44];
    int field_44;
} Unk_0208938c_44;

extern Unk_0208938c_44 data_0208938c;

int func_02009700(void) {
    return data_0208938c.field_44;
}
