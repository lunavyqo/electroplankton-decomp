// addr 0x02051dec size 0xa4

typedef struct {
    int *p00;
    int _04;
    int owner;
    int count;
    int queue;
    int field14;
} M;

M DAT_02094800;

int func_0204b758(void);
void func_0204b76c(int);
void func_0204b7d4(void);
void func_0204a3f8(void *);

void func_02051dec(int thread, int arg1) {
    M *g = &DAT_02094800;
    int irq = func_0204b758();

    if (g->owner != thread || g->count == 0) {
        func_0204b7d4();
    } else {
        if (g->field14 != arg1) {
            func_0204b7d4();
        }
        g->count = g->count - 1;
        if (g->count == 0) {
            g->owner = (int)~2;
            g->field14 = 0;
            func_0204a3f8(&g->queue);
        }
    }
    *g->p00 = 0;
    func_0204b76c(irq);
}
