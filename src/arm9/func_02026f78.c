// addr 0x02026f78 size 0x20

void func_02028c5c(void *self, int idx);

void func_02026f78(void *self) {
    func_02028c5c(self, 0);
    *(int *)((char *)self + 0x3c) = 2;
}
