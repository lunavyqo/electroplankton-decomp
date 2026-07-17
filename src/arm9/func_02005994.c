// addr 0x02005994 size 0x28

typedef struct {
    int field00;
    int field04;
} Obj;

extern Obj *data_0206f450;

void func_02005994(int arg) {
    while (arg >= 4) {
        arg -= 4;
    }
    data_0206f450->field04 = arg;
}
