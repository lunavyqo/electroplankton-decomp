// addr 0x0203e340 size 0x48

void func_02001558(void *arg);
void func_0200e578(void *arg);
void func_02001068(void *arg);

void func_0203e340(void *self) {
    void **p = (void **)self;
    func_02001558(p[6]);   /* +0x18 */
    func_02001558(p[7]);   /* +0x1c */
    func_02001558(p[8]);   /* +0x20 */
    func_0200e578(p[9]);   /* +0x24 */
    func_0200e578(p[10]);  /* +0x28 */
    func_0200e578(p[11]);  /* +0x2c */
    func_02001068(self);
}
