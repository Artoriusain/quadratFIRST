#include <stdio.h>
#include <assert.h>
#include "kvad.h"

void tester(void) {                                 // TESTS THE SHIT OUT OF ME
    
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
