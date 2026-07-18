// addr 0x0204f4a0 size 0x20 — tail to func_0204e6f0(&data_02094674, a, b)

extern int data_02094674;
void func_0204e6f0(int *ctx, void *a, int b);

void func_0204f4a0(void *a, int b) {
    func_0204e6f0(&data_02094674, a, b);
}
