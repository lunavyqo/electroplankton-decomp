// addr 0x02058410 size 0x38
// Walk null-terminated function-pointer table (static ctors/dtors).
//
// NONMATCHING: (div=14) pure C of the obvious loop; target has unusual cmp r4,#0
// after loading table base (was asm paste).

typedef void (*VoidFunc)(void);
extern VoidFunc data_0205d00c[];

void func_02058410(void) {
    VoidFunc *p = data_0205d00c;
    for (;;) {
        VoidFunc f = *p;
        if (f == 0) {
            break;
        }
        f();
        p++;
    }
}
