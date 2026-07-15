// addr 0x0205655c size 0x8
// Soft-float quiet NaN bit pattern (0x7fffffff).
// MATCH pure C under mwccarm 1.2/sp2p3 -O4,p.

unsigned func_0205655c(void) {
    return ~0x80000000u;
}
