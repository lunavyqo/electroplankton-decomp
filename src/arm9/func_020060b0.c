// addr 0x020060b0 size 0xa4

typedef struct {
    char pad[0x44];
    unsigned char field44;
} Obj;

extern Obj *data_0206f658;
extern unsigned char data_020585ec[];

void func_02043124(void *p, int a);
void func_020455e4(void *p, int a, int b);

void func_020060b0(int arg) {
    Obj *obj;
    unsigned char f;

    while (arg >= 4) {
        arg -= 4;
    }
    if (arg < 0) {
        obj = data_0206f658;
        obj->field44 = (unsigned char)(obj->field44 + 1);
    } else {
        data_0206f658->field44 = (unsigned char)arg;
    }
    obj = data_0206f658;
    f = obj->field44;
    if (f >= 4) {
        obj->field44 = 0;
    }
    func_02043124((char *)data_0206f658 + 4, 0);
    obj = data_0206f658;
    f = obj->field44;
    func_020455e4((char *)obj + 4, 9, data_020585ec[f]);
}
