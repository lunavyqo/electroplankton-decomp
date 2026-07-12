// addr 0x02014bf0 size 0xfc

typedef signed short s16;
typedef unsigned short u16;

typedef struct {
    char unk[0x20];
    void *field20;
    void *field24[16];
} Obj_02014bf0;

extern Obj_02014bf0 *data_0208f380;

void *func_02016000(void *a, int b, int c, int d, int e);
unsigned int func_02002570(void);
void *func_0201517c(void *a, s16 *vec, int b, u16 c);

void func_02014bf0(void *arg) {
    void *created;
    int i;
    int z;
    s16 vec[3];
    unsigned int r;
    int inv = -1;

    created = func_02016000(arg, 0, 0, 0, 0);
    data_0208f380->field20 = created;

    i = 0;
    z = i;
    for (; i < 0x10; i++) {
        r = func_02002570();
        vec[0] = (s16)(r % 0x3000);

        r = func_02002570();
        if (r & 0x300) {
            vec[0] = (s16)((vec[0] ^ inv) + 1);
        }

        r = func_02002570();
        vec[1] = (s16)(r & 0x1fff);

        r = func_02002570();
        if (r & 0x300) {
            vec[1] = (s16)((vec[1] ^ inv) + 1);
        }
        vec[2] = (s16)z;

        r = func_02002570();
        data_0208f380->field24[i] = func_0201517c(
            data_0208f380->field20,
            vec,
            0xe0,
            (u16)r
        );
        z -= 0x19a;
    }
}
