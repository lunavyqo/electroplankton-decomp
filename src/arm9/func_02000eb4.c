// addr 0x02000eb4 size 0x68

typedef struct {
    void *field00;
    int field04;
    int field08;
} Owner;

typedef struct {
    void *ptr0;
    void *ptr4;
    void *ptr8;
    int size;
    int field10;
} Arena;

void *func_02000f28(int size);
void func_0204a598(void *a, void *b, void *arena, void *c, int size, int d);

void *func_02000eb4(Owner *self, int arg1, int arg2) {
    Arena *arena;
    int flag;

    flag = self->field08;
    arena = (Arena *)func_02000f28(self->field04);
    arena->field10 = arg2;
    if (arg1 >= 0) {
        if (arg1 < 0x20) {
            flag = arg1;
        }
    }
    func_0204a598(arena->ptr0, self->field00, arena, arena->ptr8, arena->size, flag);
    return arena;
}
