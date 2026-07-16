// addr 0x02050958 size 0xf0

extern unsigned int data_02094730;

void func_02050e80(int a);
void func_02050ebc(int a, int b, int c);

int func_02050958(int mode, int arg1, int arg2, int arg3) {
    volatile unsigned short *flag = (volatile unsigned short *)0x04000304;
    volatile unsigned int *tick = (volatile unsigned int *)0x027ffc3c;

    if (mode != 0) {
        if (mode == 1) {
            if (arg2 == 0) {
                unsigned int diff = *tick - data_02094730;
                if (diff <= 7) {
                    return 0;
                }
            }
            if (arg1 != 0) {
                if (arg3 != 0) {
                    func_02050e80(arg1);
                } else {
                    func_02050ebc(arg1, 0, 0);
                }
            }
            *flag |= 1;
        }
    } else {
        unsigned short f;
        f = *flag;
        f = (unsigned short)(f & ~1);
        *flag = f;
        data_02094730 = *tick;
        if (arg1 != 0) {
            if (arg3 != 0) {
                func_02050e80(arg1);
            } else {
                func_02050ebc(arg1, 0, 0);
            }
        }
    }
    return 1;
}
