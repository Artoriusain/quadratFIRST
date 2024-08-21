#include <stdio.h>
#include <math.h>

//-------------------------------------------------------------
//! Solves a square equation using ax^2 + bx + c= 0
//!
//! @param [in] a a-coefficient (copied)
//! @param [in] b b-coefficient (copied)
//! @param [in] c c-coefficient (copied)
//! @param [out] x1 The 1st (and sometimes only) root (pointer)
//! @param [out] x2 The 2nd root (pointer)
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns INF_ROOTS.
//-------------------------------------------------------------

struct coef {
    double a;
    double b;
    double c;
};


enum RootNumber {
    ZERO_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2,
    INF_ROOTS  = 3,
};

                                                                                                    //todo
RootNumber square_solve(struct coef coefficient, double *x1, double *x2) {                          //прототипы функций
    double D = coefficient.b*coefficient.b - 4*coefficient.a*coefficient.c;

    if (coefficient.a == 0 && coefficient.b == 0) {
        return INF_ROOTS;
    }
    if (coefficient.a == 0 && coefficient.b != 0) {
        *x1 = -coefficient.c/coefficient.b;
        return ONE_ROOT;
    }
    if (D < 0) {
        return ZERO_ROOTS;
    }
    double root_D = sqrt(D);
    *x1 = (-coefficient.b + root_D)/(2*coefficient.a);
    *x2 = (-coefficient.b - root_D)/(2*coefficient.a);

    if (*x1 == *x2) {
        return ONE_ROOT;
    }
    return TWO_ROOTS;
}


struct coef coef_read(void) {

    int coef_count = 0;
    int cur_ch = 0;

    while(1) {

        struct coef eqParam = {0, 0, 0};
        coef_count = scanf("%lg %lg %lg", &eqParam.a, &eqParam.b, &eqParam.c);

        if (coef_count == 3) {

            return eqParam;
        }
        printf("# НЕПРАВИЛЬНО, ПОПРОБУЙ ЕЩЁ РАЗ\n");

        while ((cur_ch = getchar()) != '\n' && cur_ch != EOF) {}
    }
}


int main() {

    printf("# ПОЖАЛУЙСТА ВВЕДИ КОЭФФИЦИЕНТЫ\n");

    struct coef eqParam = coef_read();


    printf("# МЫ СПРАВИЛИСЬ \n a = %lg\n b = %lg\n c = %lg\n", eqParam.a, eqParam.b, eqParam.c);

    double x1 = 0, x2 = 0;

    RootNumber root_count = square_solve(eqParam, &x1, &x2);

    switch(root_count) {

        case 0:         printf("# СОРИ БРАТАНЧИК КОРНЕЙ НЕТ\n");
                        break;

        case 1:         printf("# ОПАААА КОРЕНЬ ОДИН И ЭТО ");
                        printf("%lg\n", x1);
                        break;

        case 2:         printf("# ДВА КОРНЯ РОДНОЙ ");
                        printf("%lg or %lg\n", x1, x2);
                        break;

        case 3:         printf("# INFIMNOGA ROOTS\n");
                        break;

        default:        printf("# МЫ НАПОРТАЧИЛИ\n");
                        break;
    }

    return 0;
}


