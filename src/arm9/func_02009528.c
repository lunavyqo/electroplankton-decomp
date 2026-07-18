// addr 0x02009528 size 0x14 — base + i*0xc via mla

typedef struct {
    unsigned char data[0xc];
} Unk_0205d374;

extern Unk_0205d374 data_0205d374[];

Unk_0205d374 *func_02009528(int i) {
    return &data_0205d374[i];
}
