// addr 0x0203389c size 0xc

typedef struct {
    unsigned char pad[0x584];
    unsigned int *ptr;
} Unk_3389c;

unsigned int func_0203389c(Unk_3389c *self) {
    return *self->ptr;
}
