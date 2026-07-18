// addr 0x02033c60 size 0x10

void *func_02001558(void *arg);

typedef struct {
    unsigned char pad[0x34];
    void *field_34;
} Unk_33c60;

void *func_02033c60(Unk_33c60 *self) {
    return func_02001558(self->field_34);
}
