// addr 0x02006534 size 0xa0

typedef struct {
    int field00;
    int field04;
    int field08[5];
    int field1c[5];
    int field30[5];
} Obj_02006534;

extern Obj_02006534 *data_0206f658;
extern int data_020675b0;

void func_02043100(void *p);
void func_02002910(void);
void func_02043124(void *p, int a);

void func_02006534(void) {
    int i;
    int off;

    data_020675b0 = 0xff;
    func_02043100(data_0206f658);
    func_02043100(&data_0206f658->field04);
    for (i = 0, off = 0; i < 5; i++, off += 4) {
        func_02043100((char *)data_0206f658 + 8 + off);
        func_02043100((char *)data_0206f658 + 0x1c + off);
        func_02043100((char *)data_0206f658 + 0x30 + off);
    }
    func_02002910();
    func_02043124(&data_0206f658->field04, 0);
}
