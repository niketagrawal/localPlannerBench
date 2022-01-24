/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) pointRobot_n2_05_H10_model_ ## ID
#endif

#include <math.h> 
#include "pointRobot_n2_05_H10_model.h"

#ifndef casadi_real
#define casadi_real pointRobot_n2_05_H10_float
#endif

#ifndef casadi_int
#define casadi_int solver_int32_default
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_f1 CASADI_PREFIX(f1)
#define casadi_f2 CASADI_PREFIX(f2)
#define casadi_f3 CASADI_PREFIX(f3)
#define casadi_f4 CASADI_PREFIX(f4)
#define casadi_f5 CASADI_PREFIX(f5)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s10 CASADI_PREFIX(s10)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_s4 CASADI_PREFIX(s4)
#define casadi_s5 CASADI_PREFIX(s5)
#define casadi_s6 CASADI_PREFIX(s6)
#define casadi_s7 CASADI_PREFIX(s7)
#define casadi_s8 CASADI_PREFIX(s8)
#define casadi_s9 CASADI_PREFIX(s9)
#define casadi_sq CASADI_PREFIX(sq)

/* Symbol visibility in DLLs */
#if 0
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

casadi_real casadi_sq(casadi_real x) { return x*x;}

static const casadi_int casadi_s0[11] = {7, 1, 0, 7, 0, 1, 2, 3, 4, 5, 6};
static const casadi_int casadi_s1[34] = {30, 1, 0, 30, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
static const casadi_int casadi_s2[5] = {1, 1, 0, 1, 0};
static const casadi_int casadi_s3[17] = {1, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0};
static const casadi_int casadi_s4[18] = {14, 1, 0, 14, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
static const casadi_int casadi_s5[34] = {14, 7, 0, 12, 24, 24, 24, 24, 24, 24, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13};
static const casadi_int casadi_s6[8] = {4, 1, 0, 4, 0, 1, 2, 3};
static const casadi_int casadi_s7[7] = {3, 1, 0, 3, 0, 1, 2};
static const casadi_int casadi_s8[9] = {3, 4, 0, 0, 0, 1, 2, 1, 2};
static const casadi_int casadi_s9[9] = {4, 4, 0, 1, 2, 2, 2, 2, 3};
static const casadi_int casadi_s10[15] = {1, 7, 0, 1, 2, 3, 4, 5, 5, 5, 0, 0, 0, 0, 0};

/* pointRobot_n2_05_H10_objective_0:(i0[7],i1[30])->(o0,o1[1x7]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a3, a4, a5, a6, a7, a8, a9;
  a0=arg[0]? arg[0][0] : 0;
  a1=arg[1]? arg[1][6] : 0;
  a0=(a0-a1);
  a1=arg[1]? arg[1][4] : 0;
  a2=(a1*a0);
  a3=(a0*a2);
  a4=arg[0]? arg[0][1] : 0;
  a5=arg[1]? arg[1][7] : 0;
  a4=(a4-a5);
  a5=arg[1]? arg[1][5] : 0;
  a6=(a5*a4);
  a7=(a4*a6);
  a3=(a3+a7);
  a7=arg[0]? arg[0][2] : 0;
  a8=arg[1]? arg[1][2] : 0;
  a9=(a8*a7);
  a10=(a7*a9);
  a11=arg[0]? arg[0][3] : 0;
  a12=arg[1]? arg[1][3] : 0;
  a13=(a12*a11);
  a14=(a11*a13);
  a10=(a10+a14);
  a3=(a3+a10);
  a10=arg[1]? arg[1][13] : 0;
  a14=arg[0]? arg[0][4] : 0;
  a15=casadi_sq(a14);
  a15=(a10*a15);
  a3=(a3+a15);
  a15=arg[0]? arg[0][5] : 0;
  a16=arg[1]? arg[1][0] : 0;
  a17=(a16*a15);
  a18=(a15*a17);
  a19=arg[0]? arg[0][6] : 0;
  a20=arg[1]? arg[1][1] : 0;
  a21=(a20*a19);
  a22=(a19*a21);
  a18=(a18+a22);
  a3=(a3+a18);
  if (res[0]!=0) res[0][0]=a3;
  a1=(a1*a0);
  a2=(a2+a1);
  if (res[1]!=0) res[1][0]=a2;
  a5=(a5*a4);
  a6=(a6+a5);
  if (res[1]!=0) res[1][1]=a6;
  a8=(a8*a7);
  a9=(a9+a8);
  if (res[1]!=0) res[1][2]=a9;
  a12=(a12*a11);
  a13=(a13+a12);
  if (res[1]!=0) res[1][3]=a13;
  a14=(a14+a14);
  a14=(a14*a10);
  if (res[1]!=0) res[1][4]=a14;
  a16=(a16*a15);
  a17=(a17+a16);
  if (res[1]!=0) res[1][5]=a17;
  a20=(a20*a19);
  a21=(a21+a20);
  if (res[1]!=0) res[1][6]=a21;
  return 0;
}

int pointRobot_n2_05_H10_objective_0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

int pointRobot_n2_05_H10_objective_0_alloc_mem(void) {
  return 0;
}

int pointRobot_n2_05_H10_objective_0_init_mem(int mem) {
  return 0;
}

void pointRobot_n2_05_H10_objective_0_free_mem(int mem) {
}

int pointRobot_n2_05_H10_objective_0_checkout(void) {
  return 0;
}

void pointRobot_n2_05_H10_objective_0_release(int mem) {
}

void pointRobot_n2_05_H10_objective_0_incref(void) {
}

void pointRobot_n2_05_H10_objective_0_decref(void) {
}

casadi_int pointRobot_n2_05_H10_objective_0_n_in(void) { return 2;}

casadi_int pointRobot_n2_05_H10_objective_0_n_out(void) { return 2;}

casadi_real pointRobot_n2_05_H10_objective_0_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_objective_0_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_objective_0_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_objective_0_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_objective_0_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s2;
    case 1: return casadi_s3;
    default: return 0;
  }
}

int pointRobot_n2_05_H10_objective_0_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* pointRobot_n2_05_H10_inequalities_0:(i0[7],i1[30])->(o0[14],o1[14x7,24nz]) */
static int casadi_f1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a3, a30, a31, a32, a33, a34, a4, a5, a6, a7, a8, a9;
  a0=arg[0]? arg[0][0] : 0;
  a1=arg[1]? arg[1][14] : 0;
  a2=(a0-a1);
  a3=casadi_sq(a2);
  a4=arg[0]? arg[0][1] : 0;
  a5=arg[1]? arg[1][15] : 0;
  a6=(a4-a5);
  a7=casadi_sq(a6);
  a3=(a3+a7);
  a3=sqrt(a3);
  a7=arg[1]? arg[1][16] : 0;
  a8=(a3-a7);
  a9=arg[1]? arg[1][8] : 0;
  a8=(a8-a9);
  if (res[0]!=0) res[0][0]=a8;
  a8=arg[1]? arg[1][17] : 0;
  a10=(a0-a8);
  a11=casadi_sq(a10);
  a12=arg[1]? arg[1][18] : 0;
  a13=(a4-a12);
  a14=casadi_sq(a13);
  a11=(a11+a14);
  a11=sqrt(a11);
  a14=arg[1]? arg[1][19] : 0;
  a15=(a11-a14);
  a15=(a15-a9);
  if (res[0]!=0) res[0][1]=a15;
  a15=arg[1]? arg[1][20] : 0;
  a16=(a0-a15);
  a17=casadi_sq(a16);
  a18=arg[1]? arg[1][21] : 0;
  a19=(a4-a18);
  a20=casadi_sq(a19);
  a17=(a17+a20);
  a17=sqrt(a17);
  a20=arg[1]? arg[1][22] : 0;
  a21=(a17-a20);
  a21=(a21-a9);
  if (res[0]!=0) res[0][2]=a21;
  a21=arg[1]? arg[1][23] : 0;
  a22=(a0-a21);
  a23=casadi_sq(a22);
  a24=arg[1]? arg[1][24] : 0;
  a25=(a4-a24);
  a26=casadi_sq(a25);
  a23=(a23+a26);
  a23=sqrt(a23);
  a26=arg[1]? arg[1][25] : 0;
  a27=(a23-a26);
  a27=(a27-a9);
  if (res[0]!=0) res[0][3]=a27;
  a27=arg[1]? arg[1][26] : 0;
  a28=(a0-a27);
  a29=casadi_sq(a28);
  a30=arg[1]? arg[1][27] : 0;
  a31=(a4-a30);
  a32=casadi_sq(a31);
  a29=(a29+a32);
  a29=sqrt(a29);
  a32=arg[1]? arg[1][28] : 0;
  a33=(a29-a32);
  a33=(a33-a9);
  if (res[0]!=0) res[0][4]=a33;
  a1=(a0-a1);
  a33=casadi_sq(a1);
  a5=(a4-a5);
  a34=casadi_sq(a5);
  a33=(a33+a34);
  a33=sqrt(a33);
  a7=(a33-a7);
  a7=(a7-a9);
  if (res[0]!=0) res[0][5]=a7;
  a8=(a0-a8);
  a7=casadi_sq(a8);
  a12=(a4-a12);
  a34=casadi_sq(a12);
  a7=(a7+a34);
  a7=sqrt(a7);
  a14=(a7-a14);
  a14=(a14-a9);
  if (res[0]!=0) res[0][6]=a14;
  a15=(a0-a15);
  a14=casadi_sq(a15);
  a18=(a4-a18);
  a34=casadi_sq(a18);
  a14=(a14+a34);
  a14=sqrt(a14);
  a20=(a14-a20);
  a20=(a20-a9);
  if (res[0]!=0) res[0][7]=a20;
  a21=(a0-a21);
  a20=casadi_sq(a21);
  a24=(a4-a24);
  a34=casadi_sq(a24);
  a20=(a20+a34);
  a20=sqrt(a20);
  a26=(a20-a26);
  a26=(a26-a9);
  if (res[0]!=0) res[0][8]=a26;
  a27=(a0-a27);
  a26=casadi_sq(a27);
  a30=(a4-a30);
  a34=casadi_sq(a30);
  a26=(a26+a34);
  a26=sqrt(a26);
  a32=(a26-a32);
  a32=(a32-a9);
  if (res[0]!=0) res[0][9]=a32;
  a32=arg[1]? arg[1][9] : 0;
  a32=(a0-a32);
  if (res[0]!=0) res[0][10]=a32;
  a32=arg[1]? arg[1][11] : 0;
  a32=(a32-a0);
  if (res[0]!=0) res[0][11]=a32;
  a32=arg[1]? arg[1][10] : 0;
  a32=(a4-a32);
  if (res[0]!=0) res[0][12]=a32;
  a32=arg[1]? arg[1][12] : 0;
  a32=(a32-a4);
  if (res[0]!=0) res[0][13]=a32;
  a2=(a2/a3);
  if (res[1]!=0) res[1][0]=a2;
  a10=(a10/a11);
  if (res[1]!=0) res[1][1]=a10;
  a16=(a16/a17);
  if (res[1]!=0) res[1][2]=a16;
  a22=(a22/a23);
  if (res[1]!=0) res[1][3]=a22;
  a28=(a28/a29);
  if (res[1]!=0) res[1][4]=a28;
  a1=(a1/a33);
  if (res[1]!=0) res[1][5]=a1;
  a8=(a8/a7);
  if (res[1]!=0) res[1][6]=a8;
  a15=(a15/a14);
  if (res[1]!=0) res[1][7]=a15;
  a21=(a21/a20);
  if (res[1]!=0) res[1][8]=a21;
  a27=(a27/a26);
  if (res[1]!=0) res[1][9]=a27;
  a27=1.;
  if (res[1]!=0) res[1][10]=a27;
  a21=-1.;
  if (res[1]!=0) res[1][11]=a21;
  a6=(a6/a3);
  if (res[1]!=0) res[1][12]=a6;
  a13=(a13/a11);
  if (res[1]!=0) res[1][13]=a13;
  a19=(a19/a17);
  if (res[1]!=0) res[1][14]=a19;
  a25=(a25/a23);
  if (res[1]!=0) res[1][15]=a25;
  a31=(a31/a29);
  if (res[1]!=0) res[1][16]=a31;
  a5=(a5/a33);
  if (res[1]!=0) res[1][17]=a5;
  a12=(a12/a7);
  if (res[1]!=0) res[1][18]=a12;
  a18=(a18/a14);
  if (res[1]!=0) res[1][19]=a18;
  a24=(a24/a20);
  if (res[1]!=0) res[1][20]=a24;
  a30=(a30/a26);
  if (res[1]!=0) res[1][21]=a30;
  if (res[1]!=0) res[1][22]=a27;
  if (res[1]!=0) res[1][23]=a21;
  return 0;
}

int pointRobot_n2_05_H10_inequalities_0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f1(arg, res, iw, w, mem);
}

int pointRobot_n2_05_H10_inequalities_0_alloc_mem(void) {
  return 0;
}

int pointRobot_n2_05_H10_inequalities_0_init_mem(int mem) {
  return 0;
}

void pointRobot_n2_05_H10_inequalities_0_free_mem(int mem) {
}

int pointRobot_n2_05_H10_inequalities_0_checkout(void) {
  return 0;
}

void pointRobot_n2_05_H10_inequalities_0_release(int mem) {
}

void pointRobot_n2_05_H10_inequalities_0_incref(void) {
}

void pointRobot_n2_05_H10_inequalities_0_decref(void) {
}

casadi_int pointRobot_n2_05_H10_inequalities_0_n_in(void) { return 2;}

casadi_int pointRobot_n2_05_H10_inequalities_0_n_out(void) { return 2;}

casadi_real pointRobot_n2_05_H10_inequalities_0_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_inequalities_0_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_inequalities_0_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_inequalities_0_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_inequalities_0_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s4;
    case 1: return casadi_s5;
    default: return 0;
  }
}

int pointRobot_n2_05_H10_inequalities_0_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* pointRobot_n2_05_H10_cdyn_0:(i0[4],i1[3],i2[30])->(o0[4],o1[3x4,2nz],o2[4x4,2nz]) */
static int casadi_f2(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0;
  a0=arg[0]? arg[0][2] : 0;
  if (res[0]!=0) res[0][0]=a0;
  a0=arg[0]? arg[0][3] : 0;
  if (res[0]!=0) res[0][1]=a0;
  a0=arg[1]? arg[1][1] : 0;
  if (res[0]!=0) res[0][2]=a0;
  a0=arg[1]? arg[1][2] : 0;
  if (res[0]!=0) res[0][3]=a0;
  a0=1.;
  if (res[1]!=0) res[1][0]=a0;
  if (res[1]!=0) res[1][1]=a0;
  if (res[2]!=0) res[2][0]=a0;
  if (res[2]!=0) res[2][1]=a0;
  return 0;
}

int pointRobot_n2_05_H10_cdyn_0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f2(arg, res, iw, w, mem);
}

int pointRobot_n2_05_H10_cdyn_0_alloc_mem(void) {
  return 0;
}

int pointRobot_n2_05_H10_cdyn_0_init_mem(int mem) {
  return 0;
}

void pointRobot_n2_05_H10_cdyn_0_free_mem(int mem) {
}

int pointRobot_n2_05_H10_cdyn_0_checkout(void) {
  return 0;
}

void pointRobot_n2_05_H10_cdyn_0_release(int mem) {
}

void pointRobot_n2_05_H10_cdyn_0_incref(void) {
}

void pointRobot_n2_05_H10_cdyn_0_decref(void) {
}

casadi_int pointRobot_n2_05_H10_cdyn_0_n_in(void) { return 3;}

casadi_int pointRobot_n2_05_H10_cdyn_0_n_out(void) { return 3;}

casadi_real pointRobot_n2_05_H10_cdyn_0_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_cdyn_0_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_cdyn_0_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    case 2: return "o2";
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_cdyn_0_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s6;
    case 1: return casadi_s7;
    case 2: return casadi_s1;
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_cdyn_0_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s6;
    case 1: return casadi_s8;
    case 2: return casadi_s9;
    default: return 0;
  }
}

int pointRobot_n2_05_H10_cdyn_0_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 3;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* pointRobot_n2_05_H10_cdyn_0rd_0:(i0[4],i1[3],i2[30])->(o0[4]) */
static int casadi_f3(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0;
  a0=arg[0]? arg[0][2] : 0;
  if (res[0]!=0) res[0][0]=a0;
  a0=arg[0]? arg[0][3] : 0;
  if (res[0]!=0) res[0][1]=a0;
  a0=arg[1]? arg[1][1] : 0;
  if (res[0]!=0) res[0][2]=a0;
  a0=arg[1]? arg[1][2] : 0;
  if (res[0]!=0) res[0][3]=a0;
  return 0;
}

int pointRobot_n2_05_H10_cdyn_0rd_0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f3(arg, res, iw, w, mem);
}

int pointRobot_n2_05_H10_cdyn_0rd_0_alloc_mem(void) {
  return 0;
}

int pointRobot_n2_05_H10_cdyn_0rd_0_init_mem(int mem) {
  return 0;
}

void pointRobot_n2_05_H10_cdyn_0rd_0_free_mem(int mem) {
}

int pointRobot_n2_05_H10_cdyn_0rd_0_checkout(void) {
  return 0;
}

void pointRobot_n2_05_H10_cdyn_0rd_0_release(int mem) {
}

void pointRobot_n2_05_H10_cdyn_0rd_0_incref(void) {
}

void pointRobot_n2_05_H10_cdyn_0rd_0_decref(void) {
}

casadi_int pointRobot_n2_05_H10_cdyn_0rd_0_n_in(void) { return 3;}

casadi_int pointRobot_n2_05_H10_cdyn_0rd_0_n_out(void) { return 1;}

casadi_real pointRobot_n2_05_H10_cdyn_0rd_0_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_cdyn_0rd_0_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_cdyn_0rd_0_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_cdyn_0rd_0_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s6;
    case 1: return casadi_s7;
    case 2: return casadi_s1;
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_cdyn_0rd_0_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s6;
    default: return 0;
  }
}

int pointRobot_n2_05_H10_cdyn_0rd_0_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* pointRobot_n2_05_H10_objective_1:(i0[7],i1[30])->(o0,o1[1x7,5nz]) */
static int casadi_f4(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a2, a3, a4, a5, a6, a7, a8, a9;
  a0=arg[0]? arg[0][0] : 0;
  a1=arg[1]? arg[1][6] : 0;
  a0=(a0-a1);
  a1=arg[1]? arg[1][4] : 0;
  a2=(a1*a0);
  a3=(a0*a2);
  a4=arg[0]? arg[0][1] : 0;
  a5=arg[1]? arg[1][7] : 0;
  a4=(a4-a5);
  a5=arg[1]? arg[1][5] : 0;
  a6=(a5*a4);
  a7=(a4*a6);
  a3=(a3+a7);
  a7=arg[0]? arg[0][2] : 0;
  a8=arg[1]? arg[1][2] : 0;
  a9=(a8*a7);
  a10=(a7*a9);
  a11=arg[0]? arg[0][3] : 0;
  a12=arg[1]? arg[1][3] : 0;
  a13=(a12*a11);
  a14=(a11*a13);
  a10=(a10+a14);
  a3=(a3+a10);
  a10=arg[1]? arg[1][13] : 0;
  a14=arg[0]? arg[0][4] : 0;
  a15=casadi_sq(a14);
  a15=(a10*a15);
  a3=(a3+a15);
  if (res[0]!=0) res[0][0]=a3;
  a1=(a1*a0);
  a2=(a2+a1);
  if (res[1]!=0) res[1][0]=a2;
  a5=(a5*a4);
  a6=(a6+a5);
  if (res[1]!=0) res[1][1]=a6;
  a8=(a8*a7);
  a9=(a9+a8);
  if (res[1]!=0) res[1][2]=a9;
  a12=(a12*a11);
  a13=(a13+a12);
  if (res[1]!=0) res[1][3]=a13;
  a14=(a14+a14);
  a14=(a14*a10);
  if (res[1]!=0) res[1][4]=a14;
  return 0;
}

int pointRobot_n2_05_H10_objective_1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f4(arg, res, iw, w, mem);
}

int pointRobot_n2_05_H10_objective_1_alloc_mem(void) {
  return 0;
}

int pointRobot_n2_05_H10_objective_1_init_mem(int mem) {
  return 0;
}

void pointRobot_n2_05_H10_objective_1_free_mem(int mem) {
}

int pointRobot_n2_05_H10_objective_1_checkout(void) {
  return 0;
}

void pointRobot_n2_05_H10_objective_1_release(int mem) {
}

void pointRobot_n2_05_H10_objective_1_incref(void) {
}

void pointRobot_n2_05_H10_objective_1_decref(void) {
}

casadi_int pointRobot_n2_05_H10_objective_1_n_in(void) { return 2;}

casadi_int pointRobot_n2_05_H10_objective_1_n_out(void) { return 2;}

casadi_real pointRobot_n2_05_H10_objective_1_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_objective_1_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_objective_1_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_objective_1_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_objective_1_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s2;
    case 1: return casadi_s10;
    default: return 0;
  }
}

int pointRobot_n2_05_H10_objective_1_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* pointRobot_n2_05_H10_inequalities_1:(i0[7],i1[30])->(o0[14],o1[14x7,24nz]) */
static int casadi_f5(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a3, a30, a31, a32, a33, a34, a4, a5, a6, a7, a8, a9;
  a0=arg[0]? arg[0][0] : 0;
  a1=arg[1]? arg[1][14] : 0;
  a2=(a0-a1);
  a3=casadi_sq(a2);
  a4=arg[0]? arg[0][1] : 0;
  a5=arg[1]? arg[1][15] : 0;
  a6=(a4-a5);
  a7=casadi_sq(a6);
  a3=(a3+a7);
  a3=sqrt(a3);
  a7=arg[1]? arg[1][16] : 0;
  a8=(a3-a7);
  a9=arg[1]? arg[1][8] : 0;
  a8=(a8-a9);
  if (res[0]!=0) res[0][0]=a8;
  a8=arg[1]? arg[1][17] : 0;
  a10=(a0-a8);
  a11=casadi_sq(a10);
  a12=arg[1]? arg[1][18] : 0;
  a13=(a4-a12);
  a14=casadi_sq(a13);
  a11=(a11+a14);
  a11=sqrt(a11);
  a14=arg[1]? arg[1][19] : 0;
  a15=(a11-a14);
  a15=(a15-a9);
  if (res[0]!=0) res[0][1]=a15;
  a15=arg[1]? arg[1][20] : 0;
  a16=(a0-a15);
  a17=casadi_sq(a16);
  a18=arg[1]? arg[1][21] : 0;
  a19=(a4-a18);
  a20=casadi_sq(a19);
  a17=(a17+a20);
  a17=sqrt(a17);
  a20=arg[1]? arg[1][22] : 0;
  a21=(a17-a20);
  a21=(a21-a9);
  if (res[0]!=0) res[0][2]=a21;
  a21=arg[1]? arg[1][23] : 0;
  a22=(a0-a21);
  a23=casadi_sq(a22);
  a24=arg[1]? arg[1][24] : 0;
  a25=(a4-a24);
  a26=casadi_sq(a25);
  a23=(a23+a26);
  a23=sqrt(a23);
  a26=arg[1]? arg[1][25] : 0;
  a27=(a23-a26);
  a27=(a27-a9);
  if (res[0]!=0) res[0][3]=a27;
  a27=arg[1]? arg[1][26] : 0;
  a28=(a0-a27);
  a29=casadi_sq(a28);
  a30=arg[1]? arg[1][27] : 0;
  a31=(a4-a30);
  a32=casadi_sq(a31);
  a29=(a29+a32);
  a29=sqrt(a29);
  a32=arg[1]? arg[1][28] : 0;
  a33=(a29-a32);
  a33=(a33-a9);
  if (res[0]!=0) res[0][4]=a33;
  a1=(a0-a1);
  a33=casadi_sq(a1);
  a5=(a4-a5);
  a34=casadi_sq(a5);
  a33=(a33+a34);
  a33=sqrt(a33);
  a7=(a33-a7);
  a7=(a7-a9);
  if (res[0]!=0) res[0][5]=a7;
  a8=(a0-a8);
  a7=casadi_sq(a8);
  a12=(a4-a12);
  a34=casadi_sq(a12);
  a7=(a7+a34);
  a7=sqrt(a7);
  a14=(a7-a14);
  a14=(a14-a9);
  if (res[0]!=0) res[0][6]=a14;
  a15=(a0-a15);
  a14=casadi_sq(a15);
  a18=(a4-a18);
  a34=casadi_sq(a18);
  a14=(a14+a34);
  a14=sqrt(a14);
  a20=(a14-a20);
  a20=(a20-a9);
  if (res[0]!=0) res[0][7]=a20;
  a21=(a0-a21);
  a20=casadi_sq(a21);
  a24=(a4-a24);
  a34=casadi_sq(a24);
  a20=(a20+a34);
  a20=sqrt(a20);
  a26=(a20-a26);
  a26=(a26-a9);
  if (res[0]!=0) res[0][8]=a26;
  a27=(a0-a27);
  a26=casadi_sq(a27);
  a30=(a4-a30);
  a34=casadi_sq(a30);
  a26=(a26+a34);
  a26=sqrt(a26);
  a32=(a26-a32);
  a32=(a32-a9);
  if (res[0]!=0) res[0][9]=a32;
  a32=arg[1]? arg[1][9] : 0;
  a32=(a0-a32);
  if (res[0]!=0) res[0][10]=a32;
  a32=arg[1]? arg[1][11] : 0;
  a32=(a32-a0);
  if (res[0]!=0) res[0][11]=a32;
  a32=arg[1]? arg[1][10] : 0;
  a32=(a4-a32);
  if (res[0]!=0) res[0][12]=a32;
  a32=arg[1]? arg[1][12] : 0;
  a32=(a32-a4);
  if (res[0]!=0) res[0][13]=a32;
  a2=(a2/a3);
  if (res[1]!=0) res[1][0]=a2;
  a10=(a10/a11);
  if (res[1]!=0) res[1][1]=a10;
  a16=(a16/a17);
  if (res[1]!=0) res[1][2]=a16;
  a22=(a22/a23);
  if (res[1]!=0) res[1][3]=a22;
  a28=(a28/a29);
  if (res[1]!=0) res[1][4]=a28;
  a1=(a1/a33);
  if (res[1]!=0) res[1][5]=a1;
  a8=(a8/a7);
  if (res[1]!=0) res[1][6]=a8;
  a15=(a15/a14);
  if (res[1]!=0) res[1][7]=a15;
  a21=(a21/a20);
  if (res[1]!=0) res[1][8]=a21;
  a27=(a27/a26);
  if (res[1]!=0) res[1][9]=a27;
  a27=1.;
  if (res[1]!=0) res[1][10]=a27;
  a21=-1.;
  if (res[1]!=0) res[1][11]=a21;
  a6=(a6/a3);
  if (res[1]!=0) res[1][12]=a6;
  a13=(a13/a11);
  if (res[1]!=0) res[1][13]=a13;
  a19=(a19/a17);
  if (res[1]!=0) res[1][14]=a19;
  a25=(a25/a23);
  if (res[1]!=0) res[1][15]=a25;
  a31=(a31/a29);
  if (res[1]!=0) res[1][16]=a31;
  a5=(a5/a33);
  if (res[1]!=0) res[1][17]=a5;
  a12=(a12/a7);
  if (res[1]!=0) res[1][18]=a12;
  a18=(a18/a14);
  if (res[1]!=0) res[1][19]=a18;
  a24=(a24/a20);
  if (res[1]!=0) res[1][20]=a24;
  a30=(a30/a26);
  if (res[1]!=0) res[1][21]=a30;
  if (res[1]!=0) res[1][22]=a27;
  if (res[1]!=0) res[1][23]=a21;
  return 0;
}

int pointRobot_n2_05_H10_inequalities_1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f5(arg, res, iw, w, mem);
}

int pointRobot_n2_05_H10_inequalities_1_alloc_mem(void) {
  return 0;
}

int pointRobot_n2_05_H10_inequalities_1_init_mem(int mem) {
  return 0;
}

void pointRobot_n2_05_H10_inequalities_1_free_mem(int mem) {
}

int pointRobot_n2_05_H10_inequalities_1_checkout(void) {
  return 0;
}

void pointRobot_n2_05_H10_inequalities_1_release(int mem) {
}

void pointRobot_n2_05_H10_inequalities_1_incref(void) {
}

void pointRobot_n2_05_H10_inequalities_1_decref(void) {
}

casadi_int pointRobot_n2_05_H10_inequalities_1_n_in(void) { return 2;}

casadi_int pointRobot_n2_05_H10_inequalities_1_n_out(void) { return 2;}

casadi_real pointRobot_n2_05_H10_inequalities_1_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_inequalities_1_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

const char* pointRobot_n2_05_H10_inequalities_1_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_inequalities_1_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

const casadi_int* pointRobot_n2_05_H10_inequalities_1_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s4;
    case 1: return casadi_s5;
    default: return 0;
  }
}

int pointRobot_n2_05_H10_inequalities_1_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
