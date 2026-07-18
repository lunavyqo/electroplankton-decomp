// addr 0x020431d4 size 0x18 — data_02091594[index * 0x24] = val (word at stride)

extern unsigned char data_02091594[];

void func_020431d4(int index, unsigned int val) {
    *(unsigned int *)(data_02091594 + index * 0x24) = val;
}
