// addr 0x02046a10 size 0x20 — OR halfword flags then tail to func_02046fe0(bits)
extern unsigned short data_02092698;
void func_02046fe0(unsigned short bits);

void func_02046a10(unsigned short bits) {
    data_02092698 = (unsigned short)(data_02092698 | bits);
    func_02046fe0(bits);
}
