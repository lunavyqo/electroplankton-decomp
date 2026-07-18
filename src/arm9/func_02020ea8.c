// addr 0x02020ea8 size 0x20

void func_02001558(void *p);
void func_02001068(void *p);

void func_02020ea8(void *self) {
    void **s = (void **)self;
    func_02001558(s[8 / 4]);
    func_02001068(self);
}
