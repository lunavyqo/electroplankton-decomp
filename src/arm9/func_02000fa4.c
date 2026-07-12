// addr 0x02000fa4 size 0xb4

typedef signed short s16;

typedef struct {
    char pad[0x20];
    int field20;
    int field24;
    char pad28[0x1c];
} FSFile; // 0x44 bytes

void func_0204f42c(FSFile *file);
int func_0204f0dc(FSFile *file, void *path);
void func_0204b7d4(void);
void *func_02001084(int size, int align, int heapId);
void func_0204ef48(FSFile *file, int a, int b);
void func_0204efb4(FSFile *file, void *buf, int size);
void func_0204f094(FSFile *file);
void func_0204af2c(void *buf, int size);

void *func_02000fa4(void *path, int *outSize, void *buf, int align, s16 heapId) {
    FSFile file;
    int size;
    void *dst;

    func_0204f42c(&file);
    if (func_0204f0dc(&file, path) == 0) {
        func_0204b7d4();
    } else {
        size = file.field24 - file.field20;
        if (buf != 0) {
            dst = buf;
        } else {
            dst = func_02001084(size, align, heapId);
        }
        func_0204ef48(&file, 0, 0);
        func_0204efb4(&file, dst, size);
        func_0204f094(&file);
        func_0204af2c(dst, size);
    }
    if (outSize != 0) {
        *outSize = size;
    }
    return dst;
}
