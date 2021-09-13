///! @file quadratic-equation_tests_header
#pragma once
#include <stdio.h>

///
//! @brief the program once, comparing the results with those already available
//!
//! @param [in] a value of a-coefficient
//! @param [in] b value of b-coefficient
//! @param [in] c value of c-coefficient
//! @param [in] TrueNumRoots value of number of true-roots
//! @param [in] TrueRoot1 value of 1-st true root
//! @param [in] TrueRoot2 value of 2-nd true root
//! @param [in] nTest test serial number
//! @param [out] NumFail pointer to the number of failed tests
//!
//! @return nothing
//!
//! @note In case of failed test prints coefficients and roots (true and counted) for this situation
///

void SoloTestRoot(double a, double b, double c, int TrueNumRoots, double TrueRoot1, double TrueRoot2, int nTest, int* NumFail);

///
//! @brief the program several times using SoloTestRoot, considering all kinds of situations
//!
//! @return Number of failed tests
///

int TestSolve();

///
//! @brief the test process using TestSolve
//!
//! @return nothing
///

void TestAll();

