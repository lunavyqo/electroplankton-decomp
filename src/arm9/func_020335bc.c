// addr 0x020335bc size 0x20

void func_02001558(void *p);
void func_02001068(void *p);

void func_020335bc(void *self) {
    void **s = (void **)self;
    func_02001558(s[0xd94 / 4]);
    func_02001068(self);
}
