// addr 0x02028e5c size 0x98

typedef struct {
    char pad00[0x18];
    void *field18;
    char pad1c[0x20];
    int field3c;
} Obj_02028e5c;

void func_02028e10(Obj_02028e5c *self);
int func_02029f9c(void *p);
void func_02026f58(Obj_02028e5c *self);
void func_02028d4c(Obj_02028e5c *self);
void func_02028a74(Obj_02028e5c *self);

void func_02028e5c(Obj_02028e5c *self) {
    int state = self->field3c;

    switch (state) {
    case 0:
        func_02028e10(self);
        break;
    case 1:
        if (func_02029f9c(self->field18) == 3) {
            func_02026f58(self);
        } else {
            func_02028d4c(self);
        }
        break;
    case 2:
        if (func_02029f9c(self->field18) == 3) {
            func_02026f58(self);
        } else {
            func_02028a74(self);
        }
        break;
    }
}
