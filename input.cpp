#include <stdio.h>
#include "kvad.h"

void stdin_cls(void) {                                                      // input cleanse                        
    int cur_ch = 0;
    while ((cur_ch = getchar()) != '\n' && cur_ch != EOF) {}
}

struct coef coef_read(void) {                                               // reads three first input doubles      

    struct coef eqParam = {0, 0, 0};

    while(scanf("%lg %lg %lg", &eqParam.a, &eqParam.b, &eqParam.c) != 3) {

        printf("# НЕПРАВИЛЬНО, ПОПРОБУЙ ЕЩЁ РАЗ\n");

        stdin_cls();
    }

    return eqParam;
}
