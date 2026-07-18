// addr 0x020015c0 size 0x24

typedef struct {
    char pad[8];
    void *field08;
    char pad0c[8];
    void *field14;
} Unk_020015c0;

void *func_02049018(void);
void func_0204af2c(void *buf, void *size);

void func_020015c0(Unk_020015c0 *self) {
    self->field14 = func_02049018();
    func_0204af2c(self->field08, self->field14);
}
