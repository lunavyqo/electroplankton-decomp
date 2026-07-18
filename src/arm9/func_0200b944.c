// addr 0x0200b944 size 0x20

void func_02001068(void *p);

void func_0200b944(void *self) {
    void **s = (void **)self;
    func_02001068(s[0x98 / 4]);
    func_02001068(self);
}
