// addr 0x020578a8 size 0xc
// Double→int entry (unsigned path): set mode flag 0 and join shared body.
//
// NONMATCHING: 3-insn entry that falls into func_020578b4 body with r4=0. (div=3)
// Cannot express multi-entry shared body as a standalone pure-C function
// without matching the shared runtime as well.

/* signature: (double) → unsigned-ish via shared helper; draft only */
unsigned func_020578a8(unsigned lo, unsigned hi) {
    (void)lo;
    (void)hi;
    return 0u;
}
