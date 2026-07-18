// addr 0x0202f930 size 0x24

void func_02030b98(void);
void func_0202fbd0(int a);
void func_02030b60(void *p);

void func_0202f930(unsigned char *self) {
    func_02030b98();
    func_0202fbd0(*(int *)(self + 0x40));
    func_02030b60(self);
}
