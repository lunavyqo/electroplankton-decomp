// addr 0x0203a430 size 0x64

void func_02001558(void *p);
void func_0200e578(void *p);
void func_02001068(void *p);

typedef struct {
    int pad[4];
    void *arr[5]; // +0x10
    void *f24;    // +0x24
    void *f28;
    void *f2c;
    void *f30;
    void *f34;
} Obj;

void func_0203a430(Obj *self) {
    unsigned int i;
    for (i = 0; i < 5u; i++) {
        func_02001558(self->arr[i]);
    }
    func_02001558(self->f24);
    func_02001558(self->f28);
    func_02001558(self->f2c);
    func_0200e578(self->f30);
    func_0200e578(self->f34);
    func_02001068(self);
}
