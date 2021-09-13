#include <stdio.h>
#include <cmath>

#include "quadratic-equation_functions_header.h"
#include "quadratic-equation_tests_header.h"

int main()
{
    TestAll();

    double a_coeff = NAN;
    double b_coeff = NAN;
    double c_coeff = NAN;
    int ans = 0;

    while (ans != CORRECT_NUM_OF_COEFFS)
    {
        printf("Please, enter the coefficients of the quadratic equation\n");
        ans = scanf("%lf %lf %lf", &a_coeff, &b_coeff, &c_coeff);
        fflush(stdin);
    }

    double root1 = NAN;
    double root2 = NAN;
    int NumSolutions = 0;

    NumSolutions = Solve(a_coeff, b_coeff, c_coeff, &root1, &root2);

    switch (NumSolutions) //отельно
    {
        case ZERO_ROOTS:
            printf("This equation has no solution\n");
            break;

        case ONE_ROOT:
            printf("This equation has 1 solution: x1 = %lf\n", root1);
            break;

        case TWO_ROOTS:
            printf("This equation has 2 solutions: x1 = %lf, x2= %lf\n", root1, root2);
            break;

        case INF_ROOTS:
            printf("This equation has an infinite number of solutions\n");
            break;

        default:
            printf("main(): ERROR: number of roots = %d\n", NumSolutions);
    }
    getchar();
    return 0;
}


