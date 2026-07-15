// addr 0x02057444 size 0x1e0
// _f_mul — single-precision multiply (MW soft-float runtime implementation).
//
// NONMATCHING: this IS the soft-float helper. Compiling `return a*b` under (div=120)
// mwccarm only emits a ~12B bl stub into this symbol — the body is
// hand-structured runtime (umull, special NaN/Inf/denorm paths), not C
// codegen. Logic belongs in a later focused match; draft stub only.

float func_02057444(float a, float b) {
    /* NOT the matching body — see NONMATCHING note */
    return a * b;
}
