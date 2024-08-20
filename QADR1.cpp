#include <stdio.h>
#include <math.h>

int sqrslv(double a, double b, double c, double *x1, double *x2) {
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

 int var;
 var = sqrslv(a, b, c, &x1, &x2);


 switch(var) {

    case 0:  printf("СОРИ БРАТАНЧИК КОРНЕЙ НЕТ");
             break;

    case 1:  printf("ОПАААА КОРЕНЬ ОДИН И ЭТО %g", x1);
             break;

    case 2:  printf("ДВА КОРНЯ РОДНОЙ %g и %g", x1, x2);
             break;

    case 'INF':  printf("БЕСКОНЕЧНОСТЬ КОРНЕЙ - НЕ ПРЕДЕЛ(предел)");
                 break;

    default: printf("МЫ НАПОРТАЧИЛИ");
             break;

 }



}


