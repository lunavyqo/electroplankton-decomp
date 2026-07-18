// addr 0x02022d4c size 0x24

void func_020243a0(void);
void func_02022fdc(void *p);
void func_02023d9c(void *p);

void func_02022d4c(void *self) {
    void **s = (void **)self;
    func_020243a0();
    func_02022fdc(s[0x48 / 4]);
    func_02023d9c(self);
}
