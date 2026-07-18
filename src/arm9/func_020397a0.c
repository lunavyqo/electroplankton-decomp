// addr 0x020397a0 size 0x20

void func_02039a94(void *p);
void func_0203b444(void *p);

void func_020397a0(void *self) {
    void **s = (void **)self;
    func_02039a94(s[0x44 / 4]);
    func_0203b444(self);
}
