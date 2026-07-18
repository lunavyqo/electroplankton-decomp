// addr 0x02009a74 size 0x10

typedef struct {
    unsigned char pad[8];
    int field_8;
} Unk_0208938c_8;

extern Unk_0208938c_8 data_0208938c;

void func_02009a74(int v) {
    data_0208938c.field_8 = v;
}
