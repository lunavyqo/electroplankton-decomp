// addr 0x0201fb08 size 0x20

void func_02001558(void *p);
void func_02001068(void *p);

void func_0201fb08(void *self) {
    void **s = (void **)self;
    func_02001558(s[0x124 / 4]);
    func_02001068(self);
}
