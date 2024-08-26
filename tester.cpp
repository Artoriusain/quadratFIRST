
#include <assert.h>
#include <stdio.h>

#include "enum_errCode.h"
#include "enum_printCode.h"
#include "input.h"
#include "mymath.h"
#include "printor.h"
#include "struct_sq_equation.h"
#include "tester.h"


errCode tester(void) { // TESTS THE SHIT OUT OF ME


    FILE *file_pointer = fopen("testcases.txt", "r");

        int token_print_code = 0;
        int file_scan_res = 0;
        short error = 0;
        int test_element = 0;
        struct squareEquation test_coefs {};
        struct testVal file_tests {};

        do {
            file_scan_res = fscanf(file_pointer, "%lg %lg %lg %lg %lg %d", &file_tests.a, &file_tests.b, &file_tests.c, &file_tests.exp_root1,
                                                                           &file_tests.exp_root2, &token_print_code);

            switch(token_print_code) {
                case 0:  file_tests.exp_out = ZERO_ROOTS;
                         break;
                case 1:  file_tests.exp_out = ONE_ROOT;
                         break;
                case 2:  file_tests.exp_out = TWO_ROOTS;
                         break;
                case 3:  file_tests.exp_out = INF_ROOTS;
                         break;
                default: break;
            }

            test_coefs.a = file_tests.a;
            test_coefs.b = file_tests.b;
            test_coefs.c = file_tests.c;

            int test_out = square_solve(&test_coefs);

            if (test_out != file_tests.exp_out) {
                error = 1;
                big_printor(ERR_TESTELEM);
                printf("%d \nFunction output: %d \n Expected: %d \n", test_element, test_out, file_tests.exp_out);
            }
            if ((double_eq_check(test_coefs.x1, file_tests.exp_root1) == 0 || double_eq_check(test_coefs.x2, file_tests.exp_root2) == 0) &&
                (double_eq_check(test_coefs.x1, file_tests.exp_root2) == 0 || double_eq_check(test_coefs.x2, file_tests.exp_root1) == 0)) {
                error = 1;
                big_printor(ERR_ROOTS);
                printf("%d \nFunction output: %g %g \n Expected: %g %g \n", test_element, test_coefs.x1, test_coefs.x2,
                                                                            file_tests.exp_root1, file_tests.exp_root2);
            }
            test_coefs.x1 = 0;
            test_coefs.x2 = 0;

            if (error == 1) {
                fclose(file_pointer);
                return YES_ERRORS;
            }
        }
        while (file_scan_res != EOF);

    fclose(file_pointer);

    return NO_ERRORS;
}
