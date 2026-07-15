// addr 0x0203986c size 0x6c

int func_02039344(int x);

typedef struct {
    int pad[0x4c/4];
    int field_4c;
    int field_50;
} Obj;

void func_0203986c(Obj *self, int delta) {
    int v = func_02039344(self->field_4c);
    if (delta == 0) {
        self->field_50 = v;
        return;
    }
    self->field_50 = self->field_50 + delta;
    v = self->field_50;
    if (v > 0x3c000) {
        self->field_50 = 0x3c000;
        return;
    }
    if (v < 0x4000) {
        self->field_50 = 0x4000;
    }
}
