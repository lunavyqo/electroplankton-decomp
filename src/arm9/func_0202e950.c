// addr 0x0202e950 size 0x1c

int func_0202e950(int *self) {
    int node = *(int *)((char *)self + 0xc);
    if (node == 0) {
        return 0;
    } else {
        *(int *)((char *)self + 0xc) = *(int *)(node + 4);
        return node;
    }
}
