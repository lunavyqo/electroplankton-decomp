// addr 0x02001084 size 0x54

extern void *data_02065c84;

void func_020419a8(void *heap, unsigned short heapId);
void *func_020419f8(void *heap, int size, int align);

void *func_02001084(int size, int align, int heapId) {
    if (heapId != -1) {
        func_020419a8(data_02065c84, (unsigned short)heapId);
    }
    return func_020419f8(data_02065c84, size, align);
}
