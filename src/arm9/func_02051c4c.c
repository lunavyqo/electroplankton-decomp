// addr 0x02051c4c size 0x5c

// global blob at 0x02094800
int DAT_02094800;

int func_0204b758(void);
void func_0204b76c(int irq);
void func_0204a46c(void *queue);

int func_02051c4c(void) {
    char *g = (char *)&DAT_02094800;
    int irq = func_0204b758();
    if ((*(int *)(g + 0xe0) & 4) != 0) {
        do {
            func_0204a46c(g + 0xdc);
        } while ((*(int *)(g + 0xe0) & 4) != 0);
    }
    func_0204b76c(irq);
    return **(int **)g == 0;
}
