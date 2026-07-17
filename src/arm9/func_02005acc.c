// addr 0x02005acc size 0x28

typedef struct {
    char pad[0x50];
    unsigned char field50;
} Obj;

extern Obj *data_0206f554;

void func_02005acc(int arg) {
    while (arg >= 3) {
        arg -= 3;
    }
    data_0206f554->field50 = (unsigned char)arg;
}
