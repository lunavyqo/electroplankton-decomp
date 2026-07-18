// addr 0x0201505c size 0x20

void func_02015f4c(void *p);
void func_02016600(void *p);

void func_0201505c(void *self) {
    void **s = (void **)self;
    func_02015f4c(s[0xb0 / 4]);
    func_02016600(self);
}
