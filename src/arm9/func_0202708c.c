// addr 0x0202708c size 0x20

void func_02028140(void *p);
void func_02001068(void *p);

void func_0202708c(void *self) {
    void **s = (void **)self;
    func_02028140(s[0x4c / 4]);
    func_02001068(self);
}
