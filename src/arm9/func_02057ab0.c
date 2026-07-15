// addr 0x02057ab0 size 0x20c
// Signed integer division runtime (restoring / non-restoring style).
//
// NONMATCHING: (div=131) C `/` may bl here or use different sequence; was asm paste.
// Semantics draft: truncating toward zero signed divide.

int func_02057ab0(int n, int d) {
    return n / d;
}
