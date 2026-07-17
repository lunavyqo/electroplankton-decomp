// addr 0x02006090 size 0x20

typedef struct {
    int pad[0x11];
} Obj;

extern Obj *data_0206f658;

void func_020455e4(void *p, int a, int b);

void func_02006090(void) {
    func_020455e4(data_0206f658, 9, 0);
}
