"""A pragmatic Itanium C++ demangler, scoped to what the matching pipeline needs:
the class/method of a symbol and a best-effort argument list. The game's symbols
(e.g. _ZN5Actor9SetRangesE5Fix12IiES1_S1_S1_) ENCODE the class and every argument
type -- that is free context for the LLM tier and a free grouping key for
subsystem batching. We do not need a perfect demangler; we need class::method and
an argument count/shape. Templates and substitutions we collapse to a generic type
rather than fully resolving them.

API:
    demangle("_ZN5Actor9SetRangesE5Fix12IiES1_S1_S1_") ->
        {"qualified": "Actor::SetRanges", "class": "Actor", "method": "SetRanges",
         "args": ["Fix12", "T", "T", "T"], "nargs": 4, "ctor": False, "dtor": False}
    Returns None for names that are not _Z-mangled (plain func_xxxx / C names).
"""
import re

BUILTIN = {
    "v": "void", "b": "bool", "c": "char", "a": "signed char", "h": "unsigned char",
    "s": "short", "t": "unsigned short", "i": "int", "j": "unsigned int",
    "l": "long", "m": "unsigned long", "x": "long long", "y": "unsigned long long",
    "f": "float", "d": "double", "w": "wchar_t",
}


def _read_len_name(s, i):
    m = re.match(r"\d+", s[i:])
    if not m:
        return None, i
    n = int(m.group())
    i += len(m.group())
    return s[i:i + n], i + n


def _skip_template(s, i):
    # s[i] == 'I'; skip to matching 'E'
    depth = 0
    while i < len(s):
        if s[i] == "I":
            depth += 1
        elif s[i] == "E":
            depth -= 1
            if depth == 0:
                return i + 1
        i += 1
    return i


def _read_type(s, i):
    """Return (type_string, next_i). Best-effort; unknown -> 'T'."""
    if i >= len(s):
        return None, i
    c = s[i]
    if c in BUILTIN:
        return BUILTIN[c], i + 1
    if c in "PROK":                                  # pointer / ref / rvalue-ref / const wrapper
        inner, j = _read_type(s, i + 1)
        suf = {"P": " *", "R": " &", "O": " &&", "K": " const"}[c]
        return (inner or "T") + suf, j
    if c == "S":                                     # substitution S_ / S0_ / St ... -> generic
        m = re.match(r"S[A-Za-z0-9_]*?_", s[i:])
        return "T", i + (len(m.group()) if m else 2)
    if c.isdigit():                                  # length-prefixed name (a class type)
        name, j = _read_len_name(s, i)
        if j < len(s) and s[j] == "I":               # class<template-args>
            j = _skip_template(s, j)
        return name or "T", j
    if c == "N":                                     # nested type name N..E
        j = i + 1
        last = "T"
        while j < len(s) and s[j] != "E":
            if s[j].isdigit():
                last, j = _read_len_name(s, j)
                if j < len(s) and s[j] == "I":
                    j = _skip_template(s, j)
            else:
                j += 1
        return last or "T", j + 1
    return "T", i + 1                                # give up on this code, keep going


def demangle(sym):
    if not sym.startswith("_Z"):
        return None
    s = sym
    nested = s.startswith("_ZN")
    body = s[3:] if nested else s[2:]
    parts = []
    i = 0
    # read the qualified-name components (length-prefixed), up to 'E' if nested
    while i < len(body):
        c = body[i]
        if c == "E" and nested:
            i += 1
            break
        if c.isdigit():
            name, i = _read_len_name(body, i)
            parts.append(name)
            if i < len(body) and body[i] == "I":     # template on this component
                i = _skip_template(body, i)
        elif body[i:i + 2] in ("C1", "C2", "C3"):
            parts.append("ctor")
            i += 2
        elif body[i:i + 2] in ("D0", "D1", "D2"):
            parts.append("dtor")
            i += 2
        elif not nested:
            break
        else:
            i += 1
    if not parts:
        return None
    method = parts[-1]
    klass = parts[-2] if len(parts) >= 2 else None
    ctor = method == "ctor"
    dtor = method == "dtor"
    if (ctor or dtor) and klass:
        method = ("~" if dtor else "") + klass
    # remaining is the argument type list
    args = []
    while i < len(body):
        t, ni = _read_type(body, i)
        if ni <= i:
            break
        if t == "void" and not args:                 # f(void) == no args
            i = ni
            break
        args.append(t)
        i = ni
    qualified = "::".join(p for p in parts if p not in ("ctor", "dtor")) or method
    if (ctor or dtor):
        qualified = (klass + "::" + method) if klass else method
    return {"qualified": qualified, "class": klass, "method": method,
            "args": args, "nargs": len(args), "ctor": ctor, "dtor": dtor}


def signature(sym):
    """One-line 'Class::Method(t1, t2, ...)' or None."""
    d = demangle(sym)
    if not d:
        return None
    return f"{d['qualified']}({', '.join(d['args'])})"


if __name__ == "__main__":
    import sys
    for a in sys.argv[1:]:
        print(f"{a}\n  {demangle(a)}\n  {signature(a)}")
