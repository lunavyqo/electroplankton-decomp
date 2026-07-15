// addr 0x02051e90 size 0x9c

int DAT_02094800;

int func_0204b758(void);
void func_0204b76c(int);
void func_0204b7d4(void);
void func_0204a46c(void *);

void func_02051e90(int thread, int arg1) {
    char *g = (char *)&DAT_02094800;
    int irq = func_0204b758();

    if (*(int *)(g + 8) == thread) {
        if (*(int *)(g + 0x14) != arg1) {
            func_0204b7d4();
        }
    } else {
        while (*(volatile int *)(g + 8) != (int)~2) {
            func_0204a46c(g + 0x10);
        }
        *(int *)(g + 8) = thread;
        *(int *)(g + 0x14) = arg1;
    }
    *(int *)(g + 0xc) = *(int *)(g + 0xc) + 1;
    **(int **)g = 0;
    func_0204b76c(irq);
}
