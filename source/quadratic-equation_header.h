#include <stdio.h>

const double EPS = 1E-4;

enum SolveStatus
{
    INF_ROOTS = -1,
    CORRECT_NUM_OF_COEFFS = 3,
    TRUE = 1,
    FALSE = 0
};


/**
 * Swaps values of 2 variables
 *
 * @param [out] a pointer to the 1-st variable
 * @param [out] b pointer to the 2-nd variable
 */

void swap(double* a, double* b);

/**
 * Separately sorts true-roots and counted-roots in descending order
 *
 * @param [out] TRoot1 pointer to the 1-st true-root
 * @param [out] TRoot2 pointer to the 2-nd true-root
 * @param [out] x1 pointer to the 1-st counted-root
 * @param [out] x2 pointer to the 2-nd counted-root
 */

void SortRoots(double *TRoot1, double *TRoot2, double *x1, double *x2);

/**
 * Compare values of 2 variables
 *
 * @param [in] val1 value of 1-st variable
 * @param [in] val2 value of 2-nd variable
 *
 * @return In case of equality of values returns TRUE, otherwise return FALSE
 */

bool equal(double val1, double val2);

/**
 * Solves a linear equation bx + c = 0
 *
 * @param [in] b value of b-coefficient
 * @param [in] c value of c-coefficient
 * @param [out] x1 pointer to the 1-st root
 * @param [out] x2 pointer to the 2-nd root
 *
 * @return Number of roots
 *
 * @note Pointers to the 1-st and 2-nd roots are similar in this situation.
 *       In case of infinite number of roots returns INF_ROOTS.
 */

int SolveLine(double b, double c, double *x1, double *x2);

/**
 * In case of a !=0, solves a quadratic equation ax^2 + bx + c = 0
 *
 * @param [in] a value of a-coefficient
 * @param [in] b value of b-coefficient
 * @param [in] c value of c-coefficient
 * @param [out] x1 pointer to the 1-st root
 * @param [out] x2 pointer to the 2-nd root
 *
 * @return Number of roots
 */
int SolveQuad(double a, double b, double c, double *x1, double *x2);

/**
 * Solves a quadratic equation ax^2 + bx + c = 0 in any cases using SolveQuad or SolveLine
 *
 * @param [in] a value of a-coefficient
 * @param [in] b value of b-coefficient
 * @param [in] c value of c-coefficient
 * @param [out] x1 pointer to the 1-st root
 * @param [out] x2 pointer to the 2-nd root
 *
 * @return Number of roots
 *
 * @note In case of infinite number of roots returns INF_ROOTS.
 */

int Solve(double a, double b, double c, double *x1, double *x2);

/**
 * Tests the program once, comparing the results with those already available
 *
 * @param [in] a value of a-coefficient
 * @param [in] b value of b-coefficient
 * @param [in] c value of c-coefficient
 * @param [in] TrueNumRoots value of number of true-roots
 * @param [in] TrueRoot1 value of 1-st true root
 * @param [in] TrueRoot2 value of 2-nd true root
 * @param [in] nTest test serial number
 * @param [out] NumFail pointer to the number of failed tests
 *
 * @note In case of failed test prints coefficients and roots (true and counted) for this situation
 */

void SoloTestRoot(double a, double b, double c, int TrueNumRoots, double TrueRoot1, double TrueRoot2, int nTest, int* NumFail);

/**
 * Tests the program several times using SoloTestRoot, considering all kinds of situations
 *
 * @return Number of failed tests
 */

int TestSolve();
/**
 * Start the test process using TestSolve
 */
void TestAll();
