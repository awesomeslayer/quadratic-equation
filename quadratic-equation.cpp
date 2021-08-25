#include <stdio.h>
#include <math.h>

int SolveSquare(double a, double b, double c, double *x1, double *x2)
{
    int num = 0;
    int D = b * b - 4 * a * c;
    if (a == 0)
    {
        if (b == 0 && c == 0)
        {
            num = -1;
        }
        else
        {
            num = 1;
            *x1 = -(c / b);
        }
    }
    else
    {
        if (D > 0)
        {
            num = 2;
            *x1 = (-b + sqrt(D)) / (2 * a);
            *x2 = (-b - sqrt(D)) / (2 * a);
        }
        else if (D = 0)
        {
            num = 1;
            *x1 = -b / (2 * a);
        }
        else
        {
            num = 0;
        }
    }
    return num;
}

const int INF_ROOTS = -1;

int main()
{
    double a_coefficient = 0;
    double b_coefficient = 0;
    double c_coefficient = 0;
    double discriminant = 0;
    double root1 = 0;
    double root2 = 0;
    int NumSolutions = 0;

    printf("Please, enter the coefficients of the quadratic equation\n");
    scanf("%lf %lf %lf", &a_coefficient, &b_coefficient, &c_coefficient);

    NumSolutions = SolveSquare(a_coefficient, b_coefficient, c_coefficient, &root1, &root2);

    switch (NumSolutions)
    {
    case 0:
        printf("This equation has no solution");
        break;
    case 1:
        printf("This equation has 1 solution: x1 = %lf", root1);
        break;
    case 2:
        printf("This equation has 2 solutions: x1 = %lf, x2= %lf", root1, root2);
        break;
    case INF_ROOTS:
        printf("This equation has an infinite number of solutions");
        break;
    default:
        printf("main(): ERROR: number of roots = %d\n", NumSolutions);
        return 1;
    }

    return 0;
}
