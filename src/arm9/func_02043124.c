// addr 0x02043124 size 0x10 — *p tail-call to func_02042be4

void func_02042be4(void *arg);

void func_02043124(void **p) {
    func_02042be4(*p);
}
