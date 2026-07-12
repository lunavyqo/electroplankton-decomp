// addr 0x0201005c size 0x94

int func_02009a3c(void);
void func_0200cdac(int a, int b);
void func_0200cc50(int a);
int func_020025e8(void);
void func_0200b02c(void *a);
void func_02010990(void *a, int b);
void func_0201033c(void *a);

void func_0201005c(void *a, char *b) {
    if (func_02009a3c() != 0) {
        func_0200cdac(0x7c00, 0);
    } else {
        func_0200cdac(0, 0x5800);
    }
    func_0200cc50(0xffffd19a);
    if (func_02009a3c() != 0) {
        int t = func_020025e8();
        func_0200b02c(a);
        func_02010990(b + 0xc, t);
        func_02010990(b + 0x3c, t);
    } else {
        func_0201033c(b);
        func_0200b02c(a);
    }
}
