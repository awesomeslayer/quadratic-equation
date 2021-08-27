#include <stdio.h>
#include <math.h>
#include <assert.h>

const double EPS = 1E-5;

enum SolveStatus
{
    INF_ROOTS = -1,
    Correct_num = 3,
    YES = 1,
    NO = 0
};

void swap(double* a, double* b)
{
    double c = *a;

    *a = *b;
    *b = c;
}

void SortRoots(double *TRoot1, double *TRoot2, double *x1, double *x2)
{
    if(*TRoot1 < *TRoot2)
    {
        swap(TRoot1, TRoot2);
    }

    if(*x1 < *x2)
    {
        swap(x1, x2);
    }

    assert(*x1 >= *x2);
    assert(*TRoot1 >= *TRoot2);
}

bool equal(double val1, double val2)
{
    assert (isfinite (val1));
    assert (isfinite (val2));

    return (fabs(val1-val2) < EPS) ? YES : NO;
}

int SolveLine(double b, double c, double *x1, double *x2)
{
    assert(isfinite (b));
    assert(isfinite (c));
    assert(x1 != NULL);
    assert(x2 != NULL);


    if (equal(b, 0) && equal(c, 0))
    {
        return -1;
    }
    else
    {
        *x1 = *x2 = -(c / b);
        return 1;
    }
}

int SolveQuad(double a, double b, double c, double *x1, double *x2)   
{
    assert(isfinite (a));
    assert(isfinite (b));
    assert(isfinite (c));

    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);

    double D = b * b - 4 * a * c;

    if (equal(D, 0))   
    {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return 2;
    }
    else if (D > 0)
    {
        *x1 = *x2 = -b / (2 * a);
        return 1;
    }
    else
    {
        return 0;
    }
}

int Solve(double a, double b, double c, double *x1, double *x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (equal(a, 0))
    {
        return SolveLine(b, c, x1, x2);
    }
    else
    {
        return SolveQuad(a, b, c, x1, x2);
    }
}

void SoloTestRoot(double a, double b, double c, int TrueNumRoots, double TrueRoot1, double TrueRoot2, int nTest, int* NumFail)
{
    double x1 = 0;
    double x2 = 0;

    int NumRoots = Solve (a, b, c, &x1, &x2);

    SortRoots(&TrueRoot1, &TrueRoot2, &x1, &x2);

    if (NumRoots != TrueNumRoots || !equal(x1, TrueRoot1) || !equal(x2, TrueRoot2))
    {
        printf("Mistake in Test%d with coefficients a = %lf, b = %lf, c = %lf\n"
               "And roots: x1 = %lf (instead of %lf) , x2 = %lf (instead of %lf)\n",
                nTest, a, b, c, x1, TrueRoot1, x2, TrueRoot2);

        *NumFail = *NumFail + 1;
    }
    else
    {
        printf("OK in Test%d\n", nTest);
    }
}

int TestSolve()
{
    int NumFail = 0;

    SoloTestRoot(0, 0, 0, INF_ROOTS, NO, NO, 1, &NumFail);
    SoloTestRoot(1, 2, 3, 0, NO, NO, 2, &NumFail);
    SoloTestRoot(1, 2, -3, 2, 1, -3, 3, &NumFail);
    SoloTestRoot(0, 2, 1, 1, -0.5, -0.5, 4, &NumFail);
    SoloTestRoot(1, 2, 1, 1, -1, -1, 5, &NumFail);

    assert(NumFail == 0);

    return NumFail;
}


int main()
{

    int NumFailedTests = TestSolve();

    if (NumFailedTests != 0) 
    {
        printf("Failed Tests: %d \n", NumFailedTests);
        return 1;
    }

    double a_coefficient = 0;
    double b_coefficient = 0;
    double c_coefficient = 0;
    double root1 = 0;
    double root2 = -1;
    int NumSolutions = 0;
    int ans = 0;

    while (ans != Correct_num)
    {
        printf("Please, enter the coefficients of the quadratic equation\n");
        ans = scanf("%lf %lf %lf", &a_coefficient, &b_coefficient, &c_coefficient);
        fflush(stdin);
    }


    NumSolutions = Solve(a_coefficient, b_coefficient, c_coefficient, &root1, &root2);

    assert(NumSolutions <= Correct_num);

    switch (NumSolutions)
    {
    case 0:
        printf("This equation has no solution\n");
        break;

    case 1:
        printf("This equation has 1 solution: x1 = %lf\n", root1);
        break;

    case 2:
        printf("This equation has 2 solutions: x1 = %lf, x2= %lf\n", root1, root2);
        break;

    case INF_ROOTS:
        printf("This equation has an infinite number of solutions\n");
        break;

    default:
        printf("main(): ERROR: number of roots = %d\n", NumSolutions);
    }

    return 0;
}
