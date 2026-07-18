// addr 0x02035aa0 size 0x20

void func_02036f18(void *p);
void func_02001068(void *p);

void func_02035aa0(void *self) {
    void **s = (void **)self;
    func_02036f18(s[0x20 / 4]);
    func_02001068(self);
}
