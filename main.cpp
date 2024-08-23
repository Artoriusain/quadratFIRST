#include <stdio.h>
#include "kvad.h"

int main() {

    double x1 = 0, x2 = 0; 

    tester();

    printf("# ПОЖАЛУЙСТА ВВЕДИ КОЭФФИЦИЕНТЫ\n");

    struct coef eqParam = coef_read();
    eqParam.x1 = x1;
    eqParam.x2 = x2;

    printf("# МЫ СПРАВИЛИСЬ \n a = %lg\n b = %lg\n c = %lg\n", eqParam.a, eqParam.b, eqParam.c);        // for debug

    printCode root_count = square_solve(eqParam);
    big_printor(root_count);
    printx(root_count, eqParam);

    return 0;
}