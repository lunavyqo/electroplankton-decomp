// addr 0x0201e01c size 0x24

void func_0201f370(void);
void func_0201e1dc(void *p);
void func_0201f268(void *p);

void func_0201e01c(void *self) {
    void **s = (void **)self;
    func_0201f370();
    func_0201e1dc(s[0x14 / 4]);
    func_0201f268(self);
}
