// addr 0x02001604 size 0x88

void *func_02000fa4(void *path, int *outSize, void *buf, int align, short heapId);
int func_0200168c(int mode, int idx, int size);
void func_020016c8(int mode, int idx, void *buf, int off, int size);
void func_02001068(void *arg);

int func_02001604(int mode, int idx, void *path, int sizeOverride) {
    int size;
    void *buf;
    int off;

    buf = func_02000fa4(path, &size, 0, ~0x1f, (short)-1);
    if (sizeOverride != -1) {
        size = sizeOverride;
    }
    off = func_0200168c(mode, idx, size);
    func_020016c8(mode, idx, buf, off, size);
    func_02001068(buf);
    return off;
}
