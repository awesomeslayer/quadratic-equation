#include <stdio.h>

#include "quadratic-equation_header.h"

int main()
{
    TestAll();

    double a_coefficient = 0;
    double b_coefficient = 0;
    double c_coefficient = 0;
    double root1 = 0;
    double root2 = -1;
    int NumSolutions = 0;
    int ans = 0;

    while (ans != CORRECT_NUM_OF_COEFFS)
    {
        printf("Please, enter the coefficients of the quadratic equation\n");
        ans = scanf("%lf %lf %lf", &a_coefficient, &b_coefficient, &c_coefficient);
        fflush(stdin);
    }


    NumSolutions = Solve(a_coefficient, b_coefficient, c_coefficient, &root1, &root2);

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
