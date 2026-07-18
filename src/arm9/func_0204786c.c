// addr 0x0204786c size 0x24
void func_0204786c(unsigned int *self, int val) {
    if (val != 0) {
        if ((*self & 3) != 0) {
            self[4] = 1;
        }
    }
    *(unsigned char *)*self = (unsigned char)val;
}
