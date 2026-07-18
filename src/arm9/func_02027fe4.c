// addr 0x02027fe4 size 0x15c

typedef struct {
    void *field00;
    void *field04;
    void *field08;
    void *field0c;
    void *field10;
    void *field14;
    void *field18;
    void *field1c;
} Obj_02027fe4;

void *func_02001084(int size, int a, int b);
void *func_0200e5b4(void);
void func_0200e660(void *p, void *a, int b, void *c);
void func_02028378(void *p, void *arg);
void func_0200e368(void *p, int a, int b, int c, void *d);
void *func_02001604(int a, int b, void *c, int d);

/* address literals in pool (not pointer-to-pointer) */
extern char data_02062dc0[];
extern char data_02062e38[];
extern char data_02062e08[];
extern char data_02062f40[];
extern char data_02062e50[];
extern char data_02062d90[];
extern char data_02062ea4[];
extern char data_02062e88[];
extern char data_02062e6c[];

Obj_02027fe4 *func_02027fe4(void *p1, void *p2, void *p3, void *p4) {
    Obj_02027fe4 *obj;
    void *tmp;

    obj = (Obj_02027fe4 *)func_02001084(0x20, ~3, ~0);
    tmp = func_0200e5b4();
    obj->field14 = tmp;
    func_0200e660(obj->field14, data_02062dc0, 0, data_02062e38);
    tmp = func_0200e5b4();
    obj->field1c = tmp;
    func_02028378(obj->field1c, data_02062e08);
    tmp = func_0200e5b4();
    obj->field18 = tmp;
    func_0200e368(obj->field18, 0x1000, 0x800, ~0x51, data_02062f40);

    if (p1 != 0) {
        obj->field04 = p1;
    } else {
        obj->field04 = func_02001604(0, 0xd, data_02062e50, ~0);
    }
    if (p2 != 0) {
        obj->field08 = p2;
    } else {
        obj->field08 = func_02001604(0, 0xd, data_02062d90, ~0);
    }
    if (p3 != 0) {
        obj->field0c = p3;
    } else {
        obj->field0c = func_02001604(0, 0xd, data_02062ea4, ~0);
    }
    if (p4 != 0) {
        obj->field10 = p4;
    } else {
        obj->field10 = func_02001604(0, 0xd, data_02062e88, ~0);
    }
    obj->field00 = func_02001604(0, 0xe, data_02062e6c, 0x10);
    return obj;
}
