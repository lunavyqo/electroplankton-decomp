// addr 0x0203e388 size 0x118

void *func_02001084(int size, int align, int heapId);
void *func_02001564(int size);
void func_0203e608(void *p);
void func_0203e880(void *p);
void func_0203e744(void *p);
void *func_0200e5b4(void);
void func_0200e600(void *p, int a, int b, int c, void *d);
void func_0200e368(void *p, int a, int b, int c, void *d);
void func_0203e9bc(void *p, void *arg);
void *func_02001604(int a, int b, void *c, int d);

extern unsigned char data_02065400[];
extern unsigned char data_020654cc[];
extern unsigned char data_02065418[];
extern unsigned char data_02065430[];

void *func_0203e388(void **param) {
    void **obj;
    void *uVar2;

    obj = (void **)func_02001084(0x30, -4, -1);
    uVar2 = func_02001564(0x90);
    obj[6] = uVar2;
    func_0203e608(obj[6]);
    uVar2 = func_02001564(0x90);
    obj[7] = uVar2;
    func_0203e880(obj[7]);
    uVar2 = func_02001564(0x90);
    obj[8] = uVar2;
    func_0203e744(obj[8]);
    uVar2 = func_0200e5b4();
    obj[9] = uVar2;
    func_0200e600(obj[9], 0x1000, 0x1000, 0xffffffae, data_02065400);
    uVar2 = func_0200e5b4();
    obj[10] = uVar2;
    func_0200e368(obj[10], 0x1000, 0x800, 0xffffffae, data_020654cc);
    uVar2 = func_0200e5b4();
    obj[11] = uVar2;
    func_0203e9bc(obj[11], data_02065418);
    uVar2 = func_02001604(0, 0xe, data_02065430, 0x10);
    obj[1] = uVar2;
    obj[0] = param[0];
    obj[2] = param[1];
    obj[3] = param[2];
    obj[4] = param[3];
    param[4] = obj[1];
    return obj;
}
