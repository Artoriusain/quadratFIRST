#include <math.h>
#include <stdio.h>
#include "printor.h"
#include "enum_printCode.h"
#include "struct_coef.h"


void big_printor(printCode printCode_temp) {                                 // prints prompts through printCode     

    switch(printCode_temp) {

            case ZERO_ROOTS:    printf("# СОРИ БРАТАНЧИК КОРНЕЙ НЕТ\n");            
                                break;

            case ONE_ROOT:      printf("# ОПАААА КОРЕНЬ ОДИН\n");
                                break;

            case TWO_ROOTS:     printf("# ДВА КОРНЯ РОДНОЙ\n");
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

void printx(printCode numroots, struct coef ixes) {                          // prints roots of a square equation 
    
    switch(numroots) {
    case ONE_ROOT:      printf("# The root is  ");
                        printf("%g \n", ixes.x1);
                        return;

    case TWO_ROOTS:     printf("# The roots are ");
                        printf("%g %g \n", ixes.x1, ixes.x2);
                        return;
    case ZERO_ROOTS:    return;
    case INF_ROOTS:     return;
    case ERR_ROOTS:     return;
    case ERR_TESTELEM:  return;
    default:            return;
    }
}


//todo full equation solution print