// addr 0x0201507c size 0x1c — copy Vec3i to halfwords at +8,+a,+c
void func_0201507c(void *dst, int *src) {
    *(short *)((char *)dst + 8) = (short)src[0];
    *(short *)((char *)dst + 10) = (short)src[1];
    *(short *)((char *)dst + 12) = (short)src[2];
}
