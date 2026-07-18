// addr 0x0200959c size 0x10

typedef struct {
    unsigned char pad[0x24];
    int field_24;
} Unk_0208938c_24;

extern Unk_0208938c_24 data_0208938c;

void func_0200959c(int v) {
    data_0208938c.field_24 = v;
}
