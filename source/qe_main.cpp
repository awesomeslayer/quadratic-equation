#include <cmath>

#include "qe_functions.h"

#define DEBUG_MODE

#ifdef DEBUG_MODE

    #include "qe_tests.h"


#endif

int main()
{
    #ifdef DEBUG_MODE
    printf("DEBUG_MODE\n");
    TestAll();
    #endif

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
    
    PrintRoots(a_coeff, b_coeff, c_coeff, &root1, &root2);
   
    getchar();
    return 0;
}
    
