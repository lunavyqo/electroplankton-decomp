// addr 0x02012f1c size 0x24 — store a/b through double pointers

extern int *data_0208f28c;
extern int *data_0208f27c;

void func_02012f1c(int a, int b) {
    *data_0208f28c = a;
    *data_0208f27c = b;
}
