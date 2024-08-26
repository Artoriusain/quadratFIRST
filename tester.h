#ifndef TESTER_H
#define TESTER_H

struct testVal {
    double    a;
    double    b;
    double    c;
    double    exp_root1;
    double    exp_root2;
    printCode exp_out;
};

int tester(void);

#endif //TESTER_H
