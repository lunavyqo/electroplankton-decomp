// addr 0x0203e5cc size 0x3c

void *func_02001084(int size, int align, int heapId);
void func_0203e52c(void *obj);

void *func_0203e5cc(void *param) {
    void *obj = func_02001084(0x528, -4, -1);
    *(void **)((char *)obj + 0x524) = param;
    func_0203e52c(obj);
    return obj;
}
