// addr 0x020014f4 size 0x64
//
// Equivalent C (register allocation does not match under -O4,p alone):
//
//   typedef struct {
//       unsigned short cur, trg, rel, prev;
//       short x, y;
//   } TouchStatus;
//   extern unsigned char data_02065cf4;
//   extern volatile TouchStatus data_02065cfc;
//   void func_0204d710(void);
//   void func_0204fee8(void);
//   void func_0204fe3c(void *a);
//   void func_0204fcf4(void *a);
//
//   // Inlined helper with AAPCS (zero in r0, tp in r1):
//   static int clear_tp(int zero, volatile TouchStatus *tp) {
//       tp->prev = zero;
//       tp->rel = tp->prev;
//       tp->trg = tp->rel;
//       tp->cur = tp->trg;
//       tp->y = zero;
//       tp->x = tp->y;
//       return zero;
//   }
//
//   void func_020014f4(void) {
//       func_0204d710();
//       func_0204fee8();
//       func_0204fe3c(&data_02065cf4);
//       func_0204fcf4(&data_02065cf4);  // same work base as fe3c
//       clear_tp(0, &data_02065cfc);
//   }
//
// clear_tp body is byte-identical to the ROM clear sequence when compiled
// standalone; mwcc inlining reassigns r0/r1, so we emit the expanded form.

extern void func_0204d710(void);
extern void func_0204fee8(void);
extern void func_0204fe3c(void *);
extern void func_0204fcf4(void *);
extern unsigned char data_02065cf4;
extern unsigned char data_02065cfc;

asm void func_020014f4(void) {
    stmdb sp!, {lr}
    sub sp, sp, #4
    bl func_0204d710
    bl func_0204fee8
    ldr r0, =data_02065cf4
    bl func_0204fe3c
    ldr r0, =data_02065cf4
    bl func_0204fcf4
    ldr r1, =data_02065cfc
    mov r0, #0
    strh r0, [r1, #6]
    ldrh r2, [r1, #6]
    strh r2, [r1, #4]
    ldrh r2, [r1, #4]
    strh r2, [r1, #2]
    ldrh r2, [r1, #2]
    strh r2, [r1]
    strh r0, [r1, #10]
    ldrsh r2, [r1, #10]
    strh r2, [r1, #8]
    add sp, sp, #4
    ldmia sp!, {lr}
    bx lr
}
