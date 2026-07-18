// addr 0x020431ec size 0x20 — store low 16 bits at data_02091590[index * 0x24]
extern unsigned char data_02091590[];

void func_020431ec(int index, unsigned int val) {
    *(unsigned int *)(data_02091590 + index * 0x24) = (unsigned short)val;
}
