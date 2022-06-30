#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "quadratic-equation_functions_header.h"

double minimum(double a, double b, double c)
{
    a = fabs(a);
    b = fabs(b);
    c = fabs(c);

    if(a > b)
    {
        if(b > c)   return c;
        else        return b;

    }
    else
    {
        if(a > c)   return c;
        else        return a;
    }
}

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

    return (fabs(val1-val2) < EPS);
}

int SolveLine(double b, double c, double *x1, double *x2)
{
    assert(isfinite (b));
    assert(isfinite (c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);


    if (equal(b, 0) && equal(c, 0))
    {
        return INF_ROOTS;
    }
    else
    {
        *x1 = *x2 = -(c / b);
        return ONE_ROOT;
    }
}

int SolveQuad(double a, double b, double c, double *x1, double *x2)
{
    assert(isfinite (a));
    assert(isfinite (b));
    assert(isfinite (c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    // double min_coefficient = abs_minimum(a, b, c);
    // a = a/min_coefficient;
    // b = b/min_coefficient;
    // c = c/min_coefficient;

    double D = b * b - 4 * a * c;

    if (equal(D, 0))
    {
        *x1 = *x2 = -b / (2 * a);
        return ONE_ROOT;
    }
    else if (D > 0)
    {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return TWO_ROOTS;
    }
    else
    {
        return ZERO_ROOTS;
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

