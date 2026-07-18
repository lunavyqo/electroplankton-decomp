// addr 0x02028a74 size 0x1e8

typedef struct {
    int field00;
    int field04;
    int field08;
    char pad0c[8];
    int field14;
    int *field18;
    int field1c;
    char pad20[4];
    int field24;
    int field28;
    int field2c;
    int field30;
} Obj_02028a74;

typedef struct {
    char pad00[4];
    int field04;
    int field08;
    char pad0c[4];
    int field10;
    char pad14[2];
    short field16;
} Node_02028a74;

int func_02029f00(int *p);
int func_02029ee0(int *p);
Node_02028a74 *func_02029ee8(int *p, int idx);
void func_02028c5c(Obj_02028a74 *self, int idx);
void func_02028ef4(int a, int b, int c, int d);

void func_02028a74(Obj_02028a74 *self) {
    int n;
    Node_02028a74 *node;
    int ang;

    n = func_02029f00(self->field18);
    if (n < 2 || self->field18[0x984 / 4] == 0) {
        self->field08 = self->field18[0x990 / 4] + func_02029ee0(self->field18);
        return;
    }

    self->field24++;
    if (self->field24 < self->field28) {
        node = func_02029ee8(self->field18, self->field1c);
        self->field04 = self->field2c * self->field24 + (self->field18[0x98c / 4] + node->field04);
        self->field08 = self->field30 * self->field24 + (self->field18[0x990 / 4] + node->field08)
                        + func_02029ee0(self->field18);
    } else {
        self->field1c++;
        if (self->field1c > n - 2) {
            self->field1c = 0;
        }
        func_02028c5c(self, self->field1c);
        node = func_02029ee8(self->field18, self->field1c);
        self->field04 = self->field18[0x98c / 4] + node->field04;
        self->field08 = self->field18[0x990 / 4] + node->field08 + func_02029ee0(self->field18);

        ang = node->field10;
        if (ang < 0) {
            ang += 0x168000;
        }
        ang = ang % 0x168000;

        if (self->field1c == 0) {
            func_02028ef4(self->field00, ang >> 12, (self->field04 << 4) >> 12, 1);
        } else {
            func_02028ef4(self->field00, ang >> 12, (self->field04 << 4) >> 12, 0);
        }
    }

    node = func_02029ee8(self->field18, self->field1c);
    self->field14 = node->field10 - 0x5a000;
    node->field16 = 0x1000;
}
