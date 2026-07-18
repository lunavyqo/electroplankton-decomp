// addr 0x0202814c size 0x44

typedef struct {
    char pad00[0x84];
    int field84;
    short field88;
    short field8a;
    short field8c;
    char pad8e[0xe];
    void *field9c;
} Obj_0202814c;

void *func_02001084(int size, int a, int b);

void func_0202814c(void *param) {
    Obj_0202814c *obj;
    int val = 0x7fff;

    obj = (Obj_0202814c *)func_02001084(0xa0, ~3, ~0);
    obj->field9c = param;
    obj->field8a = (short)val;
    obj->field88 = (short)val;
    obj->field8c = 0;
    obj->field84 = 1;
}
