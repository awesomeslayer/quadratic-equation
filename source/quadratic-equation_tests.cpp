#include <stdio.h>
#include <assert.h>

#include "quadratic-equation_functions_header.h"
#include "quadratic-equation_tests_header.h"

void SoloTestRoot(double a, double b, double c, int TrueNumRoots, double TrueRoot1, double TrueRoot2, int nTest, int* NumFail)
{
    double x1 = 0;
    double x2 = 0;

    int NumRoots = Solve (a, b, c, &x1, &x2);

    SortRoots(&TrueRoot1, &TrueRoot2, &x1, &x2);

    if (NumRoots != TrueNumRoots || !equal(x1, TrueRoot1) || !equal(x2, TrueRoot2))
    {
        printf(" Mistake in Test%d with coefficients a = %lf, b = %lf, c = %lf\n"
               "And roots: x1 = %lf (instead of %lf) , x2 = %lf (instead of %lf)\n",
               nTest, a, b, c, x1, TrueRoot1, x2, TrueRoot2);

        *NumFail = *NumFail + 1;
    }
}

int TestSolve()
{
    int NumFail = 0;

    SoloTestRoot(0, 0, 0, INF_ROOTS, FALSE, FALSE, 1, &NumFail);
    SoloTestRoot(1, 2, 3, 0, FALSE, FALSE, 2, &NumFail);
    SoloTestRoot(1, 2, -3, 2, 1, -3, 3, &NumFail);
    SoloTestRoot(0, 2, 1, 1, -0.5, -0.5, 4, &NumFail);
    SoloTestRoot(1, 2, 1, 1, -1, -1, 5, &NumFail);

    return NumFail;

    //из файла
}

void TestAll() {
    int NumFailedTests = TestSolve();

    if (NumFailedTests != 0) {
        printf("Failed Tests: %d \n", NumFailedTests);
        assert(NumFailedTests == 0);
    } else {
        printf("All Tests OK\n");
    }
}