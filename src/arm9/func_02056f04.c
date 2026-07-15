// addr 0x02056f04 size 0x3b8
// _f_div — single-precision division (reciprocal table + Newton).
//
// NONMATCHING: (div=238) C `a/b` only bl's here. Large table-driven runtime
// (was invalidly banked as asm paste).

float func_02056f04(float a, float b) {
    return a / b;
}
