// addr 0x02022e48 size 0x20

void func_02023bf0(void *p);
void func_02001068(void *p);

void func_02022e48(void *self) {
    void **s = (void **)self;
    func_02023bf0(s[0x48 / 4]);
    func_02001068(self);
}
