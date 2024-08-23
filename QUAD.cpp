#include <assert.h>
#include <math.h>
#include <stdio.h>

const double EPS = 1e-8;

struct coef {
    double a;
    double b;
    double c;
    double x1;
    double x2;
};

enum printCode {
    ZERO_ROOTS   = 0,
    ONE_ROOT     = 1,
    TWO_ROOTS    = 2,
    INF_ROOTS    = 3,
    ERR_TESTELEM = 4,
    ERR_ROOTS    = 5,
};

void big_printor(printCode);
void stdin_cls(void);
double lin_solve(double, double);
int double_eq_check(double, double);
printCode square_solve(struct coef&);
struct coef coef_read(void);
void tester(void);
void printx(printCode, struct coef);

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

void tester(void) {
    
    struct testVal {
    double    a;
    double    b;
    double    c;
    double    exp_root1;
    double    exp_root2;
    printCode exp_out;
    };
                                                                    //todo scan 69e420, isfinite, irrational_drobi
    struct testVal tests[] = {
        {0, 0, 0, 0, 0, INF_ROOTS},             //0
        {0, 4, 8, -2, -2, ONE_ROOT},            //1
        {0, 0, 69420, 0, 0, ZERO_ROOTS},        //2
        {1, 1, -6, -3, 2, TWO_ROOTS},           //3
        {1, 1, 1, 0, 0, ZERO_ROOTS},            //4
        {-1, 0, 4, -2, 2, TWO_ROOTS},           //5
        {4, -1, -0.5, -0.25, 0.5, TWO_ROOTS},   //6
    };
    struct coef test_coefs {};
    int array_len = sizeof(tests) / sizeof(struct testVal);
    int error = 0;
    int test_element = 0;

    for (test_element = 0; test_element < array_len; test_element++) {
        test_coefs.a = tests[test_element].a;
        test_coefs.b = tests[test_element].b;
        test_coefs.c = tests[test_element].c;
        int test_out = square_solve(test_coefs);
        
        if (test_out != tests[test_element].exp_out) {
            error = 1;
            big_printor(ERR_TESTELEM);
            printf("%d \nFunction output: %d \n Expected: %d \n", test_element, test_out, tests[test_element].exp_out);
        }
        if ((double_eq_check(test_coefs.x1, tests[test_element].exp_root1) == 0 || double_eq_check(test_coefs.x2, tests[test_element].exp_root2) == 0) && 
            (double_eq_check(test_coefs.x1, tests[test_element].exp_root2) == 0 || double_eq_check(test_coefs.x2, tests[test_element].exp_root1) == 0)) {
            error = 1;
            big_printor(ERR_ROOTS);
            printf("%d \nFunction output: %g %g \n Expected: %g %g \n", test_element, test_coefs.x1, test_coefs.x2, tests[test_element].exp_root1, tests[test_element].exp_root2);
        }
        test_coefs.x1 = 0;
        test_coefs.x2 = 0;
    }
    if (error == 1) {
        exit(1);
    }
}

void big_printor(printCode printCode_temp) {                                 // prints prompts through printCode     

    switch(printCode_temp) {

            case ZERO_ROOTS:    printf("# СОРИ БРАТАНЧИК КОРНЕЙ НЕТ\n");            
                                break;

            case ONE_ROOT:      printf("# ОПАААА КОРЕНЬ ОДИН И ЭТО ");
                                break;

            case TWO_ROOTS:     printf("# ДВА КОРНЯ РОДНОЙ ");
                                break;

            case INF_ROOTS:     printf("# INFIMNOGA ROOTS\n");
                                break;

            case ERR_TESTELEM:  printf("ERROR: WRONG printCode OUTPUT: test_element ");
                                break;

            case ERR_ROOTS:     printf("ERROR: WRONG roots OUTPUT: test_element ");
                                break;
 
            default:            printf("# МЫ НАПОРТАЧИЛИ\n");
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
    
    if (abs(a-b) < EPS) {            \
        return 1;
    }
    return 0;
}

printCode square_solve(struct coef &coefficient) {                           // ax^2 + bx + c = 0 solver             
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

void printx(printCode numroots, struct coef ixes) {

    if (numroots == ONE_ROOT) { 
        printf("# The root is  ");
        printf("%g \n", ixes.x1);
        return;
    }
    if (numroots == ZERO_ROOTS) {
        printf("# The roots are ");
        printf("%g %g \n", ixes.x1, ixes.x2);
        return;
    }
    return;
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

    exit(0);
}


