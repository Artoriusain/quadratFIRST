#include <math.h>
#include <stdio.h>

#include "input.h"
#include "struct_sq_equation.h"

void stdin_cls(void) { // input cleanse
    int cur_ch = 0;
    while ((cur_ch = getchar()) != '\n' && cur_ch != EOF) {}
}

struct squareEquation coef_read(void) { // reads three first input doubles

    struct squareEquation eqParam = {0, 0, 0};

    while(scanf("%lg %lg %lg", &eqParam.a, &eqParam.b, &eqParam.c) != 3) {

        printf("# НЕПРАВИЛЬНО, ПОПРОБУЙ ЕЩЁ РАЗ\n");

        stdin_cls();
    }

    short error = 0;
    if(isfinite(eqParam.a) == 0) {
        printf("ERROR: COEFFICIENT A IS TOO BIG \n");
        error = 1;
    }
    if(isfinite(eqParam.b) == 0) {
        printf("ERROR: COEFFICIENT B IS TOO BIG \n");
        error = 1;
    }
    if(isfinite(eqParam.c) == 0) {
        printf("ERROR: COEFFICIENT C IS TOO BIG \n");
        error = 1;
    }

    if(error == 1) {
        printf("# НЕПРАВИЛЬНО, ПОПРОБУЙ ЕЩЁ РАЗ\n");

        stdin_cls();

        eqParam = coef_read();
    }

    return eqParam;
}


