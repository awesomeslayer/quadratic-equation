#include <stdio.h>
#include <math.h>

const int INF_ROOTS = -1;
const double eps = 1E-5;
const int co

double equal(double a, double b)
{
    if (fabs(a - b) <= eps)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int SolveLine(double b, double c, double *x1)
{
    if (b == 0 && c == 0)
    {
        return -1;
    }
    else
    {
        *x1 = -(c / b);
        return 1;
    }
}

int SolveQuad(double a, double b, double c, double *x1, double *x2)
{
    double D = b * b - 4 * a * c;

    if (D > 0)
    {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return 2;
    }
    else if (equal(D, 0) == 1)
    {
        *x1 = -b / (2 * a);
        return 1;
    }
    else
    {
        return 0;
    }
}

int Solve(double a, double b, double c, double *x1, double *x2)
{
    if (a == 0)
    {
        return SolveLine(b, c, x1);
    }
    else
    {
        return SolveQuad(a, b, c, x1, x2);
    }
}


int main()
{
    double a_coefficient = 0;
    double b_coefficient = 0;
    double c_coefficient = 0;
    double discriminant = 0;
    double root1 = 0;
    double root2 = 0;
    int NumSolutions = 0;
    int ans = 0;

    while (ans != correct_num)
    {
        printf("Please, enter the coefficients of the quadratic equation\n");
        ans = scanf("%lf %lf %lf", &a_coefficient, &b_coefficient, &c_coefficient);
        fflush(stdin);
    }

    NumSolutions = Solve(a_coefficient, b_coefficient, c_coefficient, &root1, &root2);

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
    }

    return 0;
}
