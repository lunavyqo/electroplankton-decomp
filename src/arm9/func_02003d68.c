// addr 0x02003d68 size 0x100
// NONMATCHING: regalloc of tagData/tagFmt/one (r0/r4/r8 vs r4/r5/r0); cmp/branch shape close

int func_02003d68(unsigned int *riff, unsigned int **outFmt, unsigned int **outData) {
    unsigned int *chunk;
    unsigned int sz;
    unsigned int id;
    int remain;
    unsigned int tagData;
    unsigned int tagFmt;
    unsigned int one;
    int foundFmt;
    int foundData;
    unsigned int type;

    foundFmt = 0;
    foundData = foundFmt;

    if (riff[0] != 0x46464952u) {
        return 0;
    }

    type = riff[2];
    remain = (int)riff[1];
    if (type != 0x45564157u) {
        return 0;
    }

    chunk = (unsigned int *)((char *)riff + 0xc);
    if (remain <= 0) {
        goto done;
    }

    tagData = 0x61746164u;
    tagFmt = 0x20746d66u;
    one = 1;

loop:
    id = *chunk;
    if (id == tagFmt) {
        goto do_fmt;
    }
    if (id == tagData) {
        goto do_data;
    }
    goto do_other;

do_fmt:
    *outFmt = chunk;
    sz = chunk[1];
    chunk = (unsigned int *)((char *)chunk + 4);
    foundFmt = one;
    remain -= (int)sz;
    chunk = (unsigned int *)((char *)chunk + (sz + 4));
    goto check;

do_data:
    *outData = chunk;
    sz = chunk[1];
    chunk = (unsigned int *)((char *)chunk + 4);
    foundData = one;
    remain -= (int)sz;
    chunk = (unsigned int *)((char *)chunk + (sz + 4));
    goto check;

do_other:
    sz = chunk[1];
    chunk = (unsigned int *)((char *)chunk + 4);
    remain -= (int)sz;
    chunk = (unsigned int *)((char *)chunk + (sz + 4));

check:
    if (foundFmt != 0) {
        if (foundData != 0) {
            return 1;
        }
    }
    if (remain > 0) {
        goto loop;
    }

done:
    return 0;
}
