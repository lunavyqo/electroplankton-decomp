// addr 0x0202faf8 size 0x20

void func_020303e8(void *p);
void func_02001068(void *p);

void func_0202faf8(void *self) {
    void **s = (void **)self;
    func_020303e8(s[0x40 / 4]);
    func_02001068(self);
}
