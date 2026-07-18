// addr 0x020095ac size 0x10

typedef struct {
    unsigned char pad[0x20];
    int field_20;
} Unk_0208938c_20;

extern Unk_0208938c_20 data_0208938c;

void func_020095ac(int v) {
    data_0208938c.field_20 = v;
}
