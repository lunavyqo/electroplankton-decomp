// addr 0x020578b4 size 0x4c
// Double→int (signed path, r4=1) soft-float partial body + tail into helpers.
//
// NONMATCHING: multi-entry runtime with bl to 0x2057cc4 and external joins. (div=19)
// Pure C cannot reconstruct the register-mode flag ABI.

int func_020578b4(unsigned lo, unsigned hi, unsigned a, unsigned b) {
    (void)lo;
    (void)hi;
    (void)a;
    (void)b;
    return 0;
}
