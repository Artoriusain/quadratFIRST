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

enum RootNumber {
    ZERO_ROOTS = 0,
    ONE        = 1,
    TWO        = 2,
    INF_ROOTS  = 3,
};

RootNumber square_solve(double a, double b, double c, double *x1, double *x2) {
    double D = b*b - 4*a*c;

    if (a == 0 && b == 0) {
        return INF_ROOTS;
}
    if (a == 0 && b != 0) {
        *x1 = -c/b;
        return ONE;
}
    if (D < 0) {
        return ZERO_ROOTS;
}
    double root_D = sqrt(D);
    *x1 = (-b + root_D)/(2*a);
    *x2 = (-b - root_D)/(2*a);

    if (*x1 == *x2) {
        return ONE;
}
    return TWO;
}


int main() {
    double a = 0, b = 0, c = 0;
    int coef_count = 0;

    printf("# ПОЖАЛУЙСТА ВВЕДИ КОЭФФИЦИЕНТЫ\n");

    while(1) {
        coef_count = scanf("%lg %lg %lg", &a, &b, &c);

        if (coef_count == 3) {
            break;
}
        printf("НЕПРАВИЛЬНО, ПОПРОБУЙ ЕЩЁ РАЗ\n");

        while ((cur_ch = getchar()) != '\n' && cur_ch != EOF) {}
}

    printf("# МЫ СПРАВИЛИСЬ \n a = %lg\n b = %lg\n c = %lg\n", a, b, c);

    double x1 = 0, x2 = 0;

    RootNumber root_count = square_solve(a, b, c, &x1, &x2);

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



}


