#include <math.h>
#include "kvad.h"

printCode square_solve(struct coef &coefficient) {                          // ax^2 + bx + c = 0 solver             
    // todo asserts!!!!!!!!!!!!  

    if (double_eq_check(coefficient.a, 0) == 1) {
        if (double_eq_check(coefficient.b, 0) == 1) {
            if (double_eq_check(coefficient.c, 0) == 1) {
                return INF_ROOTS;
            }
        return ZERO_ROOTS;
        }
        coefficient.x1 = lin_solve(coefficient.b, coefficient.c); 
        coefficient.x2 = coefficient.x1;
        return ONE_ROOT;
    }
    if (double_eq_check(coefficient.b, 0) == 1) {
        coefficient.x1 = sqrt(- coefficient.c / coefficient.a);
        coefficient.x2 = - coefficient.x1;
        return TWO_ROOTS;    
    }
    if (double_eq_check(coefficient.c, 0) == 1) {
        coefficient.x1 = lin_solve(coefficient.a, coefficient.b);
        coefficient.x2 = 0;
        return TWO_ROOTS;
    }

    double Discr = coefficient.b * coefficient.b - 4 * coefficient.a * coefficient.c;

    if (Discr < 0) {
        return ZERO_ROOTS;
    }
    if (double_eq_check(Discr, 0) == 1) {
        return ONE_ROOT;
        coefficient.x1 = (- coefficient.b + sqrt(Discr)) / (2 * coefficient.a);
        coefficient.x2 = coefficient.x1;
    }

    coefficient.x1 = (- coefficient.b + sqrt(Discr)) / (2 * coefficient.a);
    coefficient.x2 = - coefficient.b / coefficient.a - coefficient.x1;

    return TWO_ROOTS;
}

double lin_solve(double a, double b) {                                      // ax + b = 0 solver                    
    return - b / a;
}

int double_eq_check(double a, double b) {                                   // double равно                         
    
    if (abs(a-b) < EPS) {            \
        return 1;
    }
    return 0;
}

