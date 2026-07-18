// addr 0x020171f4 size 0x1c

typedef struct {
    unsigned char pad[0xac];
    int field_ac;
} Unk_020171f4;

void func_0201721c(void);

void func_020171f4(Unk_020171f4 *self) {
    func_0201721c();
    self->field_ac = 1;
}
