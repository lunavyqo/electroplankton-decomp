// addr 0x02039a48 size 0x1c

typedef struct {
    int pad[5];
    int field_14;
    int field_18;
} Item;

void func_02039a48(void *base, int index) {
    Item *item = (Item *)((char *)base + index * 0x24);
    item->field_14 = 0x10000;
    item->field_18 = 1;
}
