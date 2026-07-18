// addr 0x02021268 size 0x1c

int func_02021268(int base, int idx) {
    return *(int *)(base + idx * 0x18 + 0x14) == 1;
}
