// addr 0x0200a020 size 0x18 — data_0208938c.field_38 = 1; return 0

typedef struct {
    unsigned char pad[0x38];
    int field_38;
} Unk_0208938c_38;

extern Unk_0208938c_38 data_0208938c;

int func_0200a020(void) {
    data_0208938c.field_38 = 1;
    return 0;
}
