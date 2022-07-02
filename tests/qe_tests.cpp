#include <assert.h>
#include <stdlib.h>

#include "../source/qe_functions.h"
#include "qe_tests.h"

int SoloTestRoot(double a, double b, double c, int TrueNumRoots, double TrueRoot1, double TrueRoot2, int nTest)
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

        return 1;
    }
    
    return 0;
}

int TestSolve()
{
    FILE * in_file = fopen("tests", "r");

    if(in_file == NULL)
    {
        printf("Cannot open file.\n");
        return -1;
    }
    
    int NumFail = 0;
    
    double a = 0;
    double b = 0;
    double c = 0;
    int TrueNumRoots = 0;
    double TrueRoot1 = 0;
    double TrueRoot2 = 0; 
    int nTest = 0;

    while(fscanf(in_file, "%lf, %lf, %lf, %d, %lf, %lf, %d", &a, &b, &c, &TrueNumRoots, &TrueRoot1, &TrueRoot2, &nTest) == 7)
        NumFail = NumFail + SoloTestRoot(a, b, c, TrueNumRoots, TrueRoot1, TrueRoot2, nTest);

    fclose(in_file);
    return NumFail;
}

void TestAll() {
    int NumFailedTests = TestSolve();

    if (NumFailedTests != 0) {
        printf("Failed Tests: %d \n", NumFailedTests);
        assert(NumFailedTests == 0);
    } else {
        printf("All Tests are OK\n\n");
    }
}
