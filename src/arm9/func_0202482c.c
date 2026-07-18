// addr 0x0202482c size 0x20

void func_02001558(void *p);
void func_02001068(void *p);

void func_0202482c(void *self) {
    void **s = (void **)self;
    func_02001558(s[0]);
    func_02001068(self);
}
