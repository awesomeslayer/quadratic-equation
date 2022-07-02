///! @file quadratic-equation_header.h
#pragma once
#include <stdio.h>

const double EPS = 1E-4;

enum SolveStatus
{
    INF_ROOTS = -1,
    CORRECT_NUM_OF_COEFFS = 3,
    TRUE = 1,
    FALSE = 0,
    ONE_ROOT = 1,
    ZERO_ROOTS = 0,
    TWO_ROOTS = 2
};

///
//! @brief Return minimum of 3 variables by module
//!
//! @param a [in]
//! @param b [in]
//! @param c [in]
//!
//! @return value of minimum variable by module
///

double abs_minimum(double a, double b, double c);

///
//! @brief Swaps values of 2 variables
//!
//! @param [in] a pointer to the 1-st variable
//! @param [in] b pointer to the 2-nd variable
//!
//! @return nothing
///

void swap(double* a, double* b);

///
//! @brief Separately sorts true-roots and counted-roots in descending order
//!
//! @param [out] TRoot1 pointer to the 1-st true-root
//! @param [out] TRoot2 pointer to the 2-nd true-root
//! @param [out] x1 pointer to the 1-st counted-root
//! @param [out] x2 pointer to the 2-nd counted-root
//!
//! @return nothing
///

void SortRoots(double *TRoot1, double *TRoot2, double *x1, double *x2);

///
//! @brief values of 2 variables
//!
//! @param [in] val1 value of 1-st variable
//! @param [in] val2 value of 2-nd variable
//!
//! @return In case of equality of values returns TRUE, otherwise return FALSE
///

bool equal(double val1, double val2);

///
//! @brief a linear equation bx + c = 0
//!
//! @param [in] b value of b-coefficient
//! @param [in] c value of c-coefficient
//! @param [out] x1 pointer to the 1-st root
//! @param [out] x2 pointer to the 2-nd root
//!
//! @return Number of roots
//!
//! @note Pointers to the 1-st and 2-nd roots are similar in this situation.
//!      In case of infinite number of roots returns INF_ROOTS.
///

int SolveLine(double b, double c, double *x1, double *x2);

///
//! @brief case of a !=0, solves a quadratic equation ax^2 + bx + c = 0
//!
//! @param [in] a value of a-coefficient
//! @param [in] b value of b-coefficient
//! @param [in] c value of c-coefficient
//! @param [out] x1 pointer to the 1-st root
//! @param [out] x2 pointer to the 2-nd root
//!
//! @return Number of roots
///

int SolveQuad(double a, double b, double c, double *x1, double *x2);

///
//! @brief a quadratic equation ax^2 + bx + c = 0 in any cases using SolveQuad or SolveLine
//!
//! @param [in] a value of a-coefficient
//! @param [in] b value of b-coefficient
//! @param [in] c value of c-coefficient
//! @param [out] x1 pointer to the 1-st root
//! @param [out] x2 pointer to the 2-nd root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots returns INF_ROOTS.
///

int Solve(double a, double b, double c, double *x1, double *x2);

///
//! @brief Printing results of solving quadratic equation ax^2 + bx + c = 0 
//!
//! @param [in] a value of a-coefficient
//! @param [in] b value of b-coefficient
//! @param [in] c value of c-coefficient
//! @param [in] x1 pointer to the 1-st root
//! @param [in] x2 pointer to the 2-nd root
//!
//! @return TRUE if worked correctly, FALSE if not
//!
//! @note In case of infinite number of roots returns INF_ROOTS.
///

bool PrintRoots(double a, double b, double c, double *root1, double *root2);

