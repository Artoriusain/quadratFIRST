#include <assert.h>
#include <math.h>
#include <stdio.h>

double x1 = 0, x2 = 0;

struct coef {
    double a;
    double b;
    double c;
};

enum PrintCode {
    ZERO_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2,
    INF_ROOTS  = 3,
};

void big_printr(PrintCode);
void stdin_cls(void);
double lin_solve(double, double);
int double_eq_check(double, double);
PrintCode square_solve(struct coef, double*, double*);
struct coef coef_read(void);


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

void big_printr(PrintCode printcode_temp) {                                 // prints prompts through PrintCode     

switch(printcode_temp) {

        case ZERO_ROOTS:         printf("# СОРИ БРАТАНЧИК КОРНЕЙ НЕТ\n");            
                        break;

        case ONE_ROOT:         printf("# ОПАААА КОРЕНЬ ОДИН И ЭТО ");
                        printf("%lg\n", x1);
                        break;

        case TWO_ROOTS:         printf("# ДВА КОРНЯ РОДНОЙ ");
                        printf("%lg or %lg\n", x1, x2);
                        break;

        case INF_ROOTS:         printf("# INFIMNOGA ROOTS\n");
                        break;

        default:        printf("# МЫ НАПОРТАЧИЛИ\n");
                        break;
    }
    
}

void stdin_cls(void) {                                                      // input cleanse                        
    int cur_ch = 0;
    while ((cur_ch = getchar()) != '\n' && cur_ch != EOF) {}
}

double lin_solve(double a, double b) {                                      // ax + b = 0 solver                    
    return - b / a;
}

int double_eq_check(double a, double b) {                                   // double равно                         
    
    double check_val = 0.0000001;
    if (abs(a-b) < check_val) {             // const i mod
        return 1;
    }
    return 0;
}

PrintCode square_solve(struct coef coefficient, double *x1, double *x2) {   // ax^2 + bx + c = 0 solver             
    // todo asserts!!!!!!!!!!!!  

    if (double_eq_check(coefficient.a, 0) == 1) {
        if (double_eq_check(coefficient.b, 0) == 1) {
            return INF_ROOTS;
        }

        *x1 = lin_solve(coefficient.b, coefficient.c); 
        return ONE_ROOT;
    }
    if (double_eq_check(coefficient.b, 0) == 1) {
        *x1 = - coefficient.c/coefficient.b;
        return ONE_ROOT;    
    }
    if (double_eq_check(coefficient.c, 0) == 1) {
        *x1 = lin_solve(coefficient.a, coefficient.b);
        *x2 = 0;
    }

    double Discr = coefficient.b * coefficient.b - 4 * coefficient.a * coefficient.c;
    printf("%lg/n", Discr);

    if (Discr < 0) {
        return ZERO_ROOTS;
    }
    if (double_eq_check(Discr, 0) == 1) {
        return ONE_ROOT;
    }

    *x1 = (- coefficient.b + sqrt(Discr)) / (2 * coefficient.a);
    *x2 = - coefficient.b / coefficient.a - *x1;

    return TWO_ROOTS;
}

struct coef coef_read(void) {                                               // reads three first input doubles      

    struct coef eqParam = {0, 0, 0};

    while(scanf("%lg %lg %lg", &eqParam.a, &eqParam.b, &eqParam.c) != 3) {

        printf("# НЕПРАВИЛЬНО, ПОПРОБУЙ ЕЩЁ РАЗ\n");

        stdin_cls();
    }

    return eqParam;
}

int main() {

    printf("# ПОЖАЛУЙСТА ВВЕДИ КОЭФФИЦИЕНТЫ\n");

    struct coef eqParam = coef_read();

    printf("# МЫ СПРАВИЛИСЬ \n a = %lg\n b = %lg\n c = %lg\n", eqParam.a, eqParam.b, eqParam.c);        // for debug

    PrintCode root_count = square_solve(eqParam, &x1, &x2);
    big_printr(root_count);

    return 0;
}


