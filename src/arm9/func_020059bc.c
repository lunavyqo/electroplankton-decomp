// addr 0x020059bc size 0x64

typedef struct {
    int field00;
    int field04;
} Obj;

extern Obj *data_0206f450;
extern unsigned char data_02058494[];

void func_02002654(void *p, int a, int b, int c, int d, int e);

void func_020059bc(int idx, int e) {
    int i = idx;
    while (i >= 0x23) {
        i -= 0x23;
    }
    func_02002654(data_0206f450, 7, data_0206f450->field04,
                  data_02058494[i + 5] + 0x14, 0x50, e);
}
