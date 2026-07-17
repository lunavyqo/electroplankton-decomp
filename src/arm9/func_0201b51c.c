// addr 0x0201b51c size 0x30

typedef struct Obj {
    char pad00[0x10];
    void *field10;
    void *field14;
    void *field18;
} Obj;

void func_0200e578(void *p);
void *func_02001068(void *arg);

void func_0201b51c(Obj *self) {
    func_0200e578(self->field18);
    func_0200e578(self->field14);
    func_0200e578(self->field10);
    func_02001068(self);
}
