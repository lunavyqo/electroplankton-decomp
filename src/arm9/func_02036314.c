// addr 0x02036314 size 0x8e8
// MATCH 1.2/sp2p3 — G3 draw setup (plankton). new_var regalloc lever on FX store.

typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
void func_0203716c(int a, int b, int c, int d, int e, int f, int g);
void func_020015a8(void *p);
void func_02037edc(void *p, void *q, int z);
void func_02047e2c(int a, int b);
int func_020025e8(void);
double func_02055c10(double a, double b);
double func_020556d4(double a, double b);
double func_02055f8c(double a, double b);
extern unsigned char *data_02090f78;
extern char data_0206468c;
extern char data_0205b62c;
typedef struct 
{
  int f00;
  int f04;
  int f08;
  int f0c;
  int f10;
  int f14;
  int f18;
  int f1c;
  int pad20;
  int f24;
  int f28;
  int f2c;
  int f30;
  int f34;
  int f38;
  int f3c;
  int pad40;
  int f44;
  int pad48[2];
  void *f50;
  void *f54;
  void *f58;
  void *f5c;
  int pad60[2];
  void *f68;
  void *f6c;
} Inner;
typedef struct 
{
  char pad00[8];
  s16 f08;
  s16 f0a;
  char pad0c[2];
  s16 f0e;
  s16 f10;
  char pad12[2];
  u16 f14;
  u16 f16;
  int f18;
  char pad1c[0xc];
  s16 f28;
  char pad2a[2];
  u16 f2c;
  char pad2e[0x1f];
  unsigned char f4d;
  unsigned char f4e;
  char pad4f[0x19];
  Inner *inner;
} Obj;
void func_02036314(Obj *self)
{
  Inner *inner;
  int t0;
  int t1;
  int t2;
  int t3;
  unsigned int new_var;
  int t4;
  int t5;
  unsigned int *p;
  unsigned int *scale;
  unsigned int *trans;
  unsigned int *pop;
  unsigned int zero;
  unsigned int onek;
  unsigned int sc;
  s16 s;
  s16 sx;
  s16 sy;
  double d;
  int yi;
  unsigned char *g;
  inner = self->inner;
  t0 = func_020025e8();
  t1 = func_020025e8();
  t2 = func_020025e8();
  t3 = func_020025e8();
  t4 = func_020025e8();
  t5 = func_020025e8();
  p = (unsigned int *) 0x04000444;
  zero = 0;
  *p = zero;
  *p = zero;
  scale = (unsigned int *) 0x0400046C;
  sc = 0x1948;
  *scale = sc;
  *scale = sc;
  onek = 0x1000;
  *scale = onek;
  if ((self->f18 != 0) || (data_02090f78[0xa3] != 1))
  {
    p = (unsigned int *) 0x04000444;
    *p = 0;
    scale = (unsigned int *) 0x0400046C;
    s = self->f0e;
    *scale = (int) s;
    *scale = (int) s;
    *scale = 0x1000;
    g = data_02090f78;
    if (g[0xa3] == 0)
    {
      p = (unsigned int *) 0x04000480;
      *p = (unsigned int) self->f16;
      func_0203716c(1, t0, 0xfd7, inner->f14, inner->f34, 4, 4);
    }
    else
    {
      p = (unsigned int *) 0x04000480;
      *p = (unsigned int) self->f2c;
      sc = 0xf5c;
      *scale = sc;
      *scale = sc;
      *scale = 0x1000;
      func_0203716c(1, t0, self->f18, inner->f14, inner->f34, 4, 4);
    }
    func_020015a8(inner->f54);
    p = (unsigned int *) 0x04000448;
    *p = 1;
    p = (unsigned int *) 0x04000444;
    *p = 0;
    scale = (unsigned int *) 0x0400046C;
    s = self->f10;
    *scale = (int) s;
    *scale = (int) s;
    *scale = 0x1000;
    g = data_02090f78;
    if (g[0xa3] == 0)
    {
      p = (unsigned int *) 0x04000480;
      *p = (unsigned int) self->f16;
      func_0203716c(1, t0, 0xfd7, inner->f0c, inner->f2c, 4, 4);
    }
    else
    {
      p = (unsigned int *) 0x04000480;
      *p = (unsigned int) self->f2c;
      sc = 0x10e1;
      *scale = sc;
      *scale = sc;
      *scale = 0x1000;
      func_0203716c(1, t0, self->f18, inner->f0c, inner->f2c, 4, 4);
    }
    func_020015a8(inner->f54);
    p = (unsigned int *) 0x04000448;
    *p = 1;
  }
  func_02037edc(inner->f54, &data_0206468c, 0xffffffae);
  p = (unsigned int *) 0x04000444;
  *p = 0;
  scale = (unsigned int *) 0x0400046C;
  s = self->f0e;
  *scale = (int) s;
  *scale = (int) s;
  *scale = 0x1000;
  func_0203716c(1, t1, 0xfd7, inner->f10, inner->f30, 4, 4);
  p = (unsigned int *) 0x04000480;
  *p = (unsigned int) self->f14;
  func_020015a8(inner->f54);
  p = (unsigned int *) 0x04000448;
  *p = 1;
  p = (unsigned int *) 0x04000444;
  *p = 0;
  scale = (unsigned int *) 0x0400046C;
  s = self->f10;
  *scale = (int) s;
  *scale = (int) s;
  *scale = 0x1000;
  func_0203716c(1, t2, 0xfd7, inner->f08, inner->f28, 4, 4);
  p = (unsigned int *) 0x04000480;
  *p = (unsigned int) self->f14;
  func_020015a8(inner->f54);
  pop = (unsigned int *) 0x04000448;
  *pop = 1;
  *pop = 1;
  g = data_02090f78;
  if (g[0x98] == 0)
  {
    p = (unsigned int *) 0x04000444;
    *p = 0;
    scale = (unsigned int *) 0x0400046C;
    sc = 0xc8f;
    *scale = sc;
    *scale = sc;
    *scale = 0x1000;
    func_0203716c(1, t3, 0xfd7, inner->f18, inner->f38, 3, 3);
    {
      s32 mul = (s32) (((((long long) ((int) self->f0a)) * 0x1ccd) + 0x800) >> 12);
      trans = (unsigned int *) 0x04000470;
      *trans = 0;
      *trans = (unsigned int) (mul + ((s32) 0xfffff99a));
      *trans = 0;
    }
    sx = *((s16 *) ((&data_0205b62c) + 0xfc));
    sy = *((s16 *) ((&data_0205b62c) + 0xfe));
    func_02047e2c((int) sx, (int) sy);
    scale = (unsigned int *) 0x0400046C;
    sc = 0x70a;
    *scale = sc;
    *scale = sc;
    *scale = 0x1000;
    func_020015a8(inner->f58);
    p = (unsigned int *) 0x04000448;
    *p = 1;
    {
      s32 k;
      s32 mul;
      s32 v;
      unsigned int *tr;
      unsigned int c;
      unsigned int y;
      k = 0xb33;
      y = 0x30a;
      scale = (unsigned int *) 0x0400046C;
      *scale = (unsigned int) k;
      *scale = (unsigned int) k;
      *scale = 0x1000;
      func_0203716c(1, t5, 0xfd7, inner->f1c, inner->f3c, 3, 3);
      p = (unsigned int *) 0x04000444;
      *p = 0;
      v = self->f08;

      mul = (s32) (((((long long) v) * k) + 0x800) >> 12);
      tr = (unsigned int *) 0x04000470;
      {
        unsigned int m = (unsigned int) mul;
        unsigned int s = m + y;
        *tr = (c = 0xfffff51e);
        new_var = s;
        *tr = new_var;
        *tr = 0;
      }
      func_02047e2c((int) sx, (int) sy);

      scale = (unsigned int *) 0x0400046C;
      sc = 0x785;
      *scale = sc;
      *scale = sc;
      *scale = 0x1000;
      func_020015a8(inner->f5c);
      {
        unsigned int *pp = (unsigned int *) 0x04000448;
        unsigned int one = 1;
        *pp = one;
      }
      {
        unsigned int *pu = (unsigned int *) 0x04000444;
        *pu = 0;
      }
      v = self->f08;
      mul = (s32) (((((long long) v) * k) + 0x800) >> 12);
      tr = (unsigned int *) 0x04000470;
      c = 0xae2;
      {
        unsigned int m = (unsigned int) mul;
        unsigned int s = m + y;
        unsigned int z = 0;
        *tr = c;
        *tr = s;
        *tr = z;
      }
      {
        int a = (int) sx;
        int b = (int) sy;
        func_02047e2c(a, b);
      }
      scale = (unsigned int *) 0x0400046C;
      sc = 0x785;
      *scale = sc;
      *scale = sc;
      *scale = 0x1000;
      func_020015a8(inner->f5c);
      p = (unsigned int *) 0x04000448;
      *p = 1;
    }
  }
  else
  {
    p = (unsigned int *) 0x04000444;
    *p = 0;
    func_0203716c(1, t1, 0xfd7, inner->f00, inner->f04, 2, 2);
    scale = (unsigned int *) 0x0400046C;
    sc = 0xccd;
    *scale = sc;
    *scale = sc;
    *scale = 0x1000;
    {
      s32 mul = (s32) (((((long long) ((int) self->f0a)) * 0x1ccd) + 0x800) >> 12);
      trans = (unsigned int *) 0x04000470;
      *trans = 0;
      *trans = (unsigned int) (mul + 0x19a);
      *trans = 0;
    }
    p = (unsigned int *) 0x04000480;
    *p = (unsigned int) self->f14;
    func_020015a8(*((void **) (((int) inner->f68) + ((((int) self->f4e) - 2) * 4))));
    p = (unsigned int *) 0x04000448;
    *p = 1;
    func_0203716c(1, t3, 0xfd7, inner->f00, inner->f04, 2, 2);
    p = (unsigned int *) 0x04000444;
    *p = 0;
    scale = (unsigned int *) 0x0400046C;
    sc = 0xc8f;
    *scale = sc;
    *scale = sc;
    *scale = 0x1000;
    {
      s32 mul = (s32) (((((long long) ((int) self->f08)) * 0xb33) + 0x800) >> 12);
      trans = (unsigned int *) 0x04000470;
      *trans = 0xfffff666;
      *trans = (unsigned int) mul;
      *trans = 0;
    }
    *scale = 0x1000;
    *scale = 0x1800;
    *scale = 0x1000;
    p = (unsigned int *) 0x04000480;
    *p = (unsigned int) self->f14;
    func_020015a8(*((void **) (((int) inner->f6c) + ((((int) self->f4d) - 2) * 4))));
    p = (unsigned int *) 0x04000448;
    *p = 1;
    p = (unsigned int *) 0x04000444;
    *p = 0;
    scale = (unsigned int *) 0x0400046C;
    sc = 0xc8f;
    *scale = sc;
    *scale = sc;
    *scale = 0x1000;
    {
      s32 mul = (s32) (((((long long) ((int) self->f08)) * 0xb33) + 0x800) >> 12);
      trans = (unsigned int *) 0x04000470;
      *trans = 0x99a;
      *trans = (unsigned int) mul;
      *trans = 0;
    }
    *scale = 0x1000;
    *scale = 0x1800;
    *scale = 0x1000;
    p = (unsigned int *) 0x04000480;
    *p = (unsigned int) self->f14;
    func_020015a8(*((void **) (((int) inner->f6c) + ((((int) self->f4d) - 2) * 4))));
    p = (unsigned int *) 0x04000448;
    *p = 1;
  }
  func_0203716c(1, t4, 0xfd7, inner->f24, inner->f44, 4, 4);
  p = (unsigned int *) 0x04000444;
  *p = 0;
  d = (double) ((int) self->f28);
  d = func_02055c10(-0.0066, d);
  if (d > 0.0)
  {
    d = func_02055c10(4096.0, d);
    d = func_020556d4(0.5, d);
  }
  else
  {
    d = func_02055c10(4096.0, d);
    d = func_02055f8c(d, 0.5);
  }
  trans = (unsigned int *) 0x04000470;
  *trans = 0;
  yi = (int) d;
  *trans = (unsigned int) yi;
  *trans = 0;
  scale = (unsigned int *) 0x0400046C;
  sc = 0x2666;
  *scale = sc;
  *scale = sc;
  *scale = 0x1000;
  p = (unsigned int *) 0x04000480;
  *p = (unsigned int) self->f14;
  func_020015a8(inner->f50);
  pop = (unsigned int *) 0x04000448;
  *pop = 1;
  *pop = 1;
}
