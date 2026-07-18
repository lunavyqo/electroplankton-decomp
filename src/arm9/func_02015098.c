// addr 0x02015098 size 0x24

void func_02016e2c(void);
void func_02015f4c(void *p);
void func_02016600(void *p);

void func_02015098(void *self) {
    void **s = (void **)self;
    func_02016e2c();
    func_02015f4c(s[0xb0 / 4]);
    func_02016600(self);
}
