// addr 0x0203a494 size 0x1d4
void *func_02001084(int size, int align, int heapId);
void *func_02001564(int size);
void func_0203ac48(int idx, void *p);
void func_0203aa50(void *p);
void func_0203a914(void *p);
void func_0203a7d8(void *p);
void *func_0200e5b4(void);
void func_0200e368(void *obj, int a, int b, int c, int d);
void func_0203b070(void *obj, void *table);
void *func_02001604(int a, int b, void *c, int d);
extern int data_0206483c[];
extern int data_020649d8[];
extern void *data_02064894;
extern void *data_020648c4;
extern void *data_020648e0;
extern void *data_020648ac;
extern void *data_020648fc;
typedef struct {
    void *f0; void *f4; void *f8; void *fc;
    void *arr[5]; void *f24; void *f28; void *f2c; void *f30; void *f34;
} Obj38;
typedef struct { void *a; void *b; void *c; } Triple;

Obj38 *func_0203a494(Triple *opt) {
    Obj38 *self;
    unsigned int i;
    int *table;
    void *tmp;
    self = (Obj38 *)func_02001084(0x38, -4, -1);
    if (opt == 0) {
        i = 0;
        table = data_0206483c;
        do {
            tmp = func_02001564((table[i] << 6) + 0x50);
            self->arr[i] = tmp;
            func_0203ac48(i, self->arr[i]);
            i++;
        } while (i < 5u);
        self->f24 = func_02001564(0x150);
        func_0203aa50(self->f24);
    } else {
        table = data_0206483c;
        i = 0;
        do {
            tmp = func_02001564((table[i] << 6) + 0x50);
            self->arr[i] = tmp;
            func_0203ac48(i, self->arr[i]);
            i++;
        } while (i < 5u);
        self->f24 = func_02001564(0x150);
        func_0203aa50(self->f24);
    }
    self->f28 = func_02001564(0x90);
    func_0203a914(self->f28);
    self->f2c = func_02001564(0x90);
    func_0203a7d8(self->f2c);
    self->f30 = func_0200e5b4();
    func_0200e368(self->f30, 0x1000, 0x800, ~0x51, (int)&data_020649d8);
    self->f34 = func_0200e5b4();
    func_0203b070(self->f34, &data_02064894);
    self->f4 = func_02001604(0, 0xe, &data_020648c4, 0x10);
    if (opt == 0) {
        self->f0 = func_02001604(0, 0xd, &data_020648e0, -1);
        self->f8 = func_02001604(0, 0xd, &data_020648ac, -1);
        self->fc = func_02001604(0, 0xd, &data_020648fc, -1);
    } else {
        self->f0 = opt->a;
        self->f8 = opt->b;
        self->fc = opt->c;
    }
    return self;
}
