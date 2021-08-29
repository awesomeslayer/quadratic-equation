#include <stdio.h>

const double EPS = 1E-4;

enum SolveStatus
{
    INF_ROOTS = -1,
    Correct_num = 3,
    YES = 1,
    NO = 0
};

void swap(double* a, double* b);
void SortRoots(double *TRoot1, double *TRoot2, double *x1, double *x2);
bool equal(double val1, double val2);
int SolveLine(double b, double c, double *x1, double *x2);
int SolveQuad(double a, double b, double c, double *x1, double *x2);
int Solve(double a, double b, double c, double *x1, double *x2);
void SoloTestRoot(double a, double b, double c, int TrueNumRoots, double TrueRoot1, double TrueRoot2, int nTest, int* NumFail);
int TestSolve();
