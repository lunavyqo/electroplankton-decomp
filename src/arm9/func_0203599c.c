// addr 0x0203599c size 0x24

void func_020377bc(void);
void func_02035b64(int a);
void func_020372a4(void *p);

void func_0203599c(unsigned char *self) {
    func_020377bc();
    func_02035b64(*(int *)(self + 0x20));
    func_020372a4(self);
}
