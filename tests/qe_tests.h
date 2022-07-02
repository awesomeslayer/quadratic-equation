///! @file quadratic-equation_tests_header
#pragma once
#include <stdio.h>

///
//! @brief the program once, comparing the results with those already available in file tests.txt
//!
//! @param [in] a value of a-coefficient
//! @param [in] b value of b-coefficient
//! @param [in] c value of c-coefficient
//! @param [in] TrueNumRoots value of number of true-roots
//! @param [in] TrueRoot1 value of 1-st true root
//! @param [in] TrueRoot2 value of 2-nd true root
//! @param [in] nTest test serial number
//! 
//!
//! @return 1 if test is failed, 0 if test is good
//!
//! @note In case of failed test prints coefficients and roots (true and counted) for this situation
///
int SoloTestRoot(double a, double b, double c, int TrueNumRoots, double TrueRoot1, double TrueRoot2, int nTest);

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

