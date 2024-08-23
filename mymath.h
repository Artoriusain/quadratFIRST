#ifndef MYMATH_H
#define MYMATH_H
#include "enum_printCode.h"
#include "struct_coef.h"

const double EPS = 1e-8;

double lin_solve(double, double); 
int double_eq_check(double, double);
printCode square_solve(struct coef&);
#endif