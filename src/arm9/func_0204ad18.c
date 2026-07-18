// addr 0x0204ad18 size 0x24 — list unlink node
void func_0204ad18(int list, int node) {
    int next = *(int *)(node + 0x10);
    int prev = *(int *)(node + 0xc);
    if (next == 0) {
        *(int *)(list + 0x80) = prev;
    } else {
        *(int *)(next + 0xc) = prev;
    }
    if (prev == 0) {
        *(int *)(list + 0x7c) = next;
    } else {
        *(int *)(prev + 0x10) = next;
    }
}
