#include <assert.h>
#include <math.h>

#include "mymath.h"
#include "struct_sq_equation.h"

printCode square_solve(struct squareEquation *coefficient) { // ax^2 + bx + c = 0 solver

    assert(isnan(coefficient->a) == 0 && isnan(coefficient->b) == 0 && isnan(coefficient->c) == 0);

    coefficient->x1 = 0;
    coefficient->x2 = 0;

    if (double_eq_check(coefficient->a, 0) == 1) {
        if (double_eq_check(coefficient->b, 0) == 1) {
            if (double_eq_check(coefficient->c, 0) == 1) {
                return INF_ROOTS;
            }
        return ZERO_ROOTS;
        }
        coefficient->x1 = lin_solve(coefficient->b, coefficient->c);
        coefficient->x2 = coefficient->x1;

        assert(isnan(coefficient->x1) == 0 && isnan(coefficient->x2) == 0);

        return ONE_ROOT;
    }
    if (double_eq_check(coefficient->b, 0) == 1) {
        coefficient->x1 = sqrt(- coefficient->c / coefficient->a);
        coefficient->x2 = - coefficient->x1;

        assert(isnan(coefficient->x1) == 0 && isnan(coefficient->x2) == 0);

        return TWO_ROOTS;
    }
    if (double_eq_check(coefficient->c, 0) == 1) {
        coefficient->x1 = lin_solve(coefficient->a, coefficient->b);
        coefficient->x2 = 0;

        assert(isnan(coefficient->x1) == 0 && isnan(coefficient->x2) == 0);

        return TWO_ROOTS;
    }

    double Discr = coefficient->b * coefficient->b - 4 * coefficient->a * coefficient->c;

    if (Discr < 0) {
        return ZERO_ROOTS;
    }
    if (double_eq_check(Discr, 0) == 1) {
        coefficient->x1 = (- coefficient->b + sqrt(Discr)) / (2 * coefficient->a);
        coefficient->x2 = coefficient->x1;

        assert(isnan(coefficient->x1) == 0 && isnan(coefficient->x2) == 0);

        return ONE_ROOT;
    }

    coefficient->x1 = (- coefficient->b + sqrt(Discr)) / (2 * coefficient->a);
    coefficient->x2 = - coefficient->b / coefficient->a - coefficient->x1;

    assert(isnan(coefficient->x1) == 0 && isnan(coefficient->x2) == 0);

    return TWO_ROOTS;
}

double lin_solve(double a, double b) { // ax + b = 0 solver
    return - b / a;
}

int double_eq_check(double a, double b) { // double equation check

    if (abs(a-b) < EPS) {            \
        return 1;
    }
    return 0;
}
