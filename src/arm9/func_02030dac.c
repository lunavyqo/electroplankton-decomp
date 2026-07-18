// addr 0x02030dac size 0xc

typedef struct {
    unsigned int *ptr;
} Unk_30dac;

unsigned int func_02030dac(Unk_30dac *self) {
    return *self->ptr;
}
