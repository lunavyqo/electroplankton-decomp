// addr 0x02027fb4 size 0x30

typedef struct {
    char pad00[0x14];
    void *field14;
    void *field18;
    void *field1c;
} Obj_02027fb4;

void func_0200e578(void *p);
void func_02001068(void *arg);

void func_02027fb4(Obj_02027fb4 *self) {
    func_0200e578(self->field18);
    func_0200e578(self->field1c);
    func_0200e578(self->field14);
    func_02001068(self);
}
