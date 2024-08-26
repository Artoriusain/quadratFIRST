#include <stdio.h>

#include "enum_printCode.h"
#include "input.h"
#include "mymath.h"
#include "printor.h"
#include "struct_sq_equation.h"
#include "tester.h"

// TODO
//// - ifndef codestyle
//// \n before returns
//// rename printx
//// rename structs
//// makefile
//// int foo(double, doubleSFHASDFHASKFJHKLASHFLAFHLJAKSFH)
//// asserts !!!!!!!!!!!!!!!!!!!!!!!     SUKA NE KHOTCHU ASSERTUY BEEEEEEEEEEEEE
//// delete all refs, use PTRs instead

int main() {

    double x1 = 0, x2 = 0;

    int err_code = tester();
    if (err_code == 1 ) { // test error check
        printf("ERROR: TESTS FAILED\n");
        return 1;
    }

    printf("# ПОЖАЛУЙСТА ВВЕДИ КОЭФФИЦИЕНТЫ\n");

    struct squareEquation eqParam = coef_read();
    eqParam.x1 = x1;
    eqParam.x2 = x2;

    printf("# МЫ СПРАВИЛИСЬ \n a = %lg\n b = %lg\n c = %lg\n", eqParam.a, eqParam.b, eqParam.c); // for debug

    printCode root_count = square_solve(&eqParam);
    big_printor(root_count);
    print_sq_solutions(root_count, eqParam);

    return 0;
}
