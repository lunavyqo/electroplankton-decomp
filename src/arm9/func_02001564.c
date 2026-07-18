// addr 0x02001564 size 0x44

void *func_02001084(int size, int align, int heapId);
void func_020015f8(void *obj, void *aligned, void *src);

void *func_02001564(int size) {
    void *obj;
    char *p;

    obj = func_02001084(size + 0x24, -4, 1);
    p = (char *)obj + 0x20;
    p = p + 3;
    p = (char *)((unsigned)p & ~3u);
    func_020015f8(obj, p, (void *)size);
    return obj;
}
