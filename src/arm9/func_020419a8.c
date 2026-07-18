// addr 0x020419a8 size 0x10 — exchange halfword at +0x34 via +0x24 base

typedef struct {
    unsigned char pad[0x10];
    unsigned short field;
} Unk_419a8_sub;

typedef struct {
    unsigned char pad[0x24];
    Unk_419a8_sub sub;
} Unk_419a8;

unsigned short func_020419a8(Unk_419a8 *self, unsigned short v) {
    Unk_419a8_sub *s = &self->sub;
    unsigned short old = s->field;
    s->field = v;
    return old;
}
