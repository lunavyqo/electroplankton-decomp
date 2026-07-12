// addr 0x02000f28 size 0x7c

typedef struct {
    void *ptr0;
    void *ptr4;
    void *ptr8;
    int size;
} Arena;

void *func_02001058(void);
void *func_020419a0(void *heap);
void *func_02001084(int size, int align, int heapId);
void func_020419a8(void *heap, void *saved);
void func_0204af2c(void *ptr, int n);

void *func_02000f28(int size) {
    void *saved;
    Arena *a;
    unsigned int p0;
    unsigned int p1;
    unsigned int p2;

    saved = func_020419a0(func_02001058());
    a = (Arena *)func_02001084(size + 0xb0, -4, 0x64);

    p0 = (unsigned int)a + 0x14;
    p0 = p0 + 3;
    p0 = p0 & ~3u;

    p1 = p0 + 0x94;
    p1 = p1 + 3;
    p1 = p1 & ~3u;

    a->ptr0 = (void *)p0;
    p2 = p1 + (unsigned int)size;
    a->ptr4 = (void *)p1;
    p2 = p2 & ~3u;
    a->ptr8 = (void *)p2;
    a->size = size;

    func_020419a8(func_02001058(), saved);
    func_0204af2c(a, 0x14);
    return a;
}
