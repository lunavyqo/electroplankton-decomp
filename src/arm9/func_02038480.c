// addr 0x02038480 size 0x24

void func_02038480(unsigned int *self, unsigned int limit, unsigned int val) {
    self[3] = self[3] + 1;
    if (self[3] > limit) {
        self[3] = 0;
        self[0] = val;
    }
}
