//-------------------------------------------------------------
//! Solves a square equation using ax^2 + bx + c= 0
//!
//! @param [in] a a-coefficient (copied)
//! @param [in] b b-coefficient (copied)
//! @param [in] c c-coefficient (copied)
//! @param [out] x1 The 1st (and sometimes only) root (pointer)
//! @param [out] x2 The 2nd root (pointer)
//!
//! @return Number of roots, roots
//!
//! @note In case of infinite number of roots,
//! returns INF.
//-------------------------------------------------------------




#include <stdio.h>
#include <math.h>

int sqrslv(double a, double b, double c, double *x1, double *x2) {

 assert (std::isfinite (a));
 assert (std::isfinite (b));
 assert (std::isfinite (c));


 double D;
 D = b*b - 4*a*c;


 if (a == 0 && b == 0)  {
     return 'INF';
    }
 if (a == 0 && b != 0) {
     *x1 = -c/b;
     return 1;
 }
  if (D < 0) {
     return 0;
  }

 *x1 = (-b + sqrt(D))/(2*a);
 *x2 = (-b - sqrt(D))/(2*a);

 if (*x1 == *x2) {
     return 1;
 }

    return 2;
}


int main() {

 double a, b, c;

 printf("enter factor a\n");
 scanf("%lg", &a);
 printf("a = %g\n", a);

 printf("enter factor b\n");
 scanf("%lg", &b);
 printf("b = %g\n", b);

 printf("enter factor c\n");
 scanf("%lg", &c);
 printf("c = %g\n", c);

 double x1, x2;
 x1 = x2 = 0;

 int var = sqrslv(a, b, c, &x1, &x2);


 switch(var) {

    case 0:  printf("СОРИ БРАТАНЧИК КОРНЕЙ НЕТ");
             break;

    case 1:  printf("ОПАААА КОРЕНЬ ОДИН И ЭТО %g", x1);
             break;

    case 2:  printf("ДВА КОРНЯ РОДНОЙ %g и %g", x1, x2);
             break;

    case 'INF':  printf("INFIMNOGA ROOTS");
                 break;

    default: printf("МЫ НАПОРТАЧИЛИ");
             break;

 }



}


