// addr 0x020203a8 size 0x20

void func_02001558(void *p);
void func_02001068(void *p);

void func_020203a8(void *self) {
    void **s = (void **)self;
    func_02001558(s[4 / 4]);
    func_02001068(self);
}
