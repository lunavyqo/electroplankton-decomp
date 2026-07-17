// addr 0x0201b54c size 0x138

typedef struct Obj {
    void *field00;
    void *field04;
    void *field08;
    void *field0c;
    void *field10;
    void *field14;
    void *field18;
} Obj;

void *func_02001084(int size, int align, int heapId);
void *func_0200e5b4(void);
void func_0200e660(void *obj, void *a, int b, void *c);
void func_0200e368(void *obj, int a, int b, int c, void *d);
void *func_02001604(int a, int b, void *c, int d);

extern char data_02062088;
extern char data_02062040;
extern char data_020620a0;
extern char data_0206212c;
extern char data_020620d4;
extern char data_02062058;
extern char data_020620f0;
extern char data_020620b8;

Obj *func_0201b54c(void *a, void *b, void *c) {
    Obj *self = (Obj *)func_02001084(0x1c, -4, -1);

    self->field10 = func_0200e5b4();
    func_0200e660(self->field10, &data_02062088, 0, &data_02062040);

    self->field14 = func_0200e5b4();
    func_0200e660(self->field14, &data_020620a0, 0, &data_02062040);

    self->field18 = func_0200e5b4();
    func_0200e368(self->field18, 0x1000, 0x800, ~0x51, &data_0206212c);

    if (a != 0) {
        self->field04 = a;
    } else {
        self->field04 = func_02001604(0, 0xd, &data_020620d4, -1);
    }

    if (b != 0) {
        self->field08 = b;
    } else {
        self->field08 = func_02001604(0, 0xd, &data_02062058, -1);
    }

    if (c != 0) {
        self->field0c = c;
    } else {
        self->field0c = func_02001604(0, 0xd, &data_020620f0, -1);
    }

    self->field00 = func_02001604(0, 0xe, &data_020620b8, 0x10);
    return self;
}
