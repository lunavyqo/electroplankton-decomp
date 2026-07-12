// Object constructor/allocator
// addr 0x02023bfc size 0x68

typedef struct UnkOuter {
    char pad[0x210];
    unsigned char field210;
} UnkOuter;

typedef struct Obj {
    char pad00[0x34];
    short field34;
    short field36;
    short field38;
    unsigned char field3a;
    char pad3b[0x1d];
    void *field58; // at 0x58
} Obj;

void *func_02001084(int size, int a, int b);

extern UnkOuter *data_02090f1c;

Obj *func_02023bfc(void *arg0, int flag) {
    Obj *obj;

    obj = (Obj *)func_02001084(0x5c, -4, -1);
    obj->field58 = arg0;
    obj->field38 = 0x7fff;
    obj->field34 = 0;
    obj->field36 = 0;
    if (flag != 0) {
        obj->field3a = 6;
    } else {
        obj->field3a = data_02090f1c->field210;
    }
    return obj;
}
