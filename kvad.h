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