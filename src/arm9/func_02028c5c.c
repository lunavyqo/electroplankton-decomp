// addr 0x02028c5c size 0xf0

typedef struct {
    char pad00[4];
    int field04;
    int field08;
    char pad0c[0xc];
    void *field18;
    char pad1c[4];
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
} Obj_02028c5c;

typedef struct {
    char pad00[4];
    int field04;
    int field08;
} Node_02028c5c;

Node_02028c5c *func_02029ee8(void *p, int idx);
int func_020573fc(int a); /* float convert? */
void func_02056340(int a, int b);
void func_02057630(int a, int b);
int func_02057340(void);
int func_02045db0(int a, int b);

void func_02028c5c(Obj_02028c5c *self, int idx) {
    Node_02028c5c *n0;
    Node_02028c5c *n1;
    int t;
    int f;

    n0 = func_02029ee8(self->field18, idx);
    n1 = func_02029ee8(self->field18, idx + 1);
    t = self->field20;
    if (t > 0) {
        f = func_020573fc(t << 12);
        func_02056340(0x3f000000, f);
    } else {
        f = func_020573fc(t << 12);
        func_02057630(f, 0x3f000000);
    }
    f = func_02057340();
    self->field2c = func_02045db0(n1->field04 - n0->field04, f);

    t = self->field20;
    if (t > 0) {
        f = func_020573fc(t << 12);
        func_02056340(0x3f000000, f);
    } else {
        f = func_020573fc(t << 12);
        func_02057630(f, 0x3f000000);
    }
    f = func_02057340();
    self->field30 = func_02045db0(n1->field08 - n0->field08, f);

    self->field28 = self->field20;
    self->field24 = 0;
    self->field04 = self->field34;
    self->field08 = self->field38;
}
