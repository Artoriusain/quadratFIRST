#ifndef MYMATH_H
#define MYMATH_H

#include "enum_printCode.h"
#include "struct_sq_equation.h"

const double EPS = 1e-8;

double lin_solve(double a, double b);
int double_eq_check(double a, double b);
printCode square_solve(struct squareEquation* coefficient);

#endif //MYMATH_H
