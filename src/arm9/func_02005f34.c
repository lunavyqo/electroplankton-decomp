// addr 0x02005f34 size 0xb4

typedef struct {
    char pad[0x3c];
    int slot3c[5];
    unsigned char field50;
} Obj;

extern Obj data_0206f558;
extern Obj *data_0206f554;
extern void *data_020675b4;
extern int data_020675b0;

void func_02002950(void);
void func_02043118(void *p);
void func_020454f0(int a, void *p);
void func_02003c54(int a);
void func_02002d50(int a);

void func_02005f34(void) {
    int i;
    int j;

    func_02002950();
    data_0206f554 = &data_0206f558;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            func_02043118((char *)data_0206f554 + i * 0xc + j * 4);
        }
        data_0206f554->slot3c[i] = 0;
    }
    data_0206f554->field50 = 0;
    func_020454f0(7, data_020675b4);
    func_02003c54(0x11);
    func_02002d50(0x18);
    data_020675b0 = 7;
}
