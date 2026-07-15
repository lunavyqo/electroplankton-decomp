// addr 0x020065d4 size 0x120
// NONMATCHING: first store regalloc only (div=3): ldr/mov/str use r0/r1 vs target r2/r3; rest of function byte-identical

typedef struct {
    int field00;
    int field04;
    int arr08[5];
    int arr1c[5];
    int arr30[5];
    unsigned char field44;
    signed char field45;
    char pad46[2];
    int field48;
} Obj_020065d4;

extern Obj_020065d4 *data_0206f658;
extern int data_0206f65c;
extern Obj_020065d4 data_0206f660;
extern void *data_020675b4;
extern unsigned char data_020585ec[];
extern int data_020675b0;

void func_02002950(void);
void func_02043118(void *p);
void func_020454f0(int a, void *b);
void func_020455e4(void *p, int a, int b);
void func_02003c54(int a);
void func_02002d50(int a);

void func_020065d4(void) {
    int i;
    int off;
    Obj_020065d4 *obj;

    data_0206f65c = 1;
    func_02002950();
    data_0206f658 = &data_0206f660;
    func_02043118(&data_0206f660);
    func_02043118((char *)data_0206f658 + 4);
    for (i = 0, off = 0; i < 5; i++, off += 4) {
        func_02043118((char *)data_0206f658 + 8 + off);
        func_02043118((char *)data_0206f658 + 0x1c + off);
        func_02043118((char *)data_0206f658 + 0x30 + off);
    }
    obj = data_0206f658;
    obj->field44 = 0;
    data_0206f658->field45 = -1;
    data_0206f658->field48 = 0x78;
    func_020454f0(9, data_020675b4);
    obj = data_0206f658;
    func_020455e4((char *)obj + 4, 9, data_020585ec[obj->field44]);
    func_02003c54(0);
    func_02002d50(0);
    data_0206f65c = 0;
    data_020675b0 = 9;
}
