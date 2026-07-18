// addr 0x0204ad3c size 0x24 — list append tail
void func_0204ad3c(int list, int node) {
    int tail = *(int *)(list + 0x80);
    if (tail == 0) {
        *(int *)(list + 0x7c) = node;
    } else {
        *(int *)(tail + 0x10) = node;
    }
    *(int *)(node + 0xc) = tail;
    *(int *)(node + 0x10) = 0;
    *(int *)(list + 0x80) = node;
}
