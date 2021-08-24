#include <stdio.h>
#include <math.h>



int main()
{
    double a_coefficient = 0;
    double b_coefficient = 0;
    double c_coefficient = 0;
    double discriminant = 0;
    double root1 = 0;
    double root2 = 0;
    printf("Please, enter the coefficients of the quadratic equation\n");
    scanf("%lf %lf %lf", &a_coefficient, &b_coefficient, &c_coefficient);
    if(a_coefficient == 0)
    {
        if(b_coefficient == 0 && c_coefficient == 0)
        {
        printf("This equation has an infinite number of solutions");
        }
        else
        {
        root1 = -(c_coefficient/b_coefficient);
        printf("A single root of this equation is:");
        printf("%lf", root1);
        }
    }
    else
    {
        discriminant = b_coefficient*b_coefficient - 4*a_coefficient*c_coefficient;
        if(discriminant == 0)
        {
            root1 = -(b_coefficient/(2*a_coefficient));
            printf("A single root of this equation is:");
            printf("%lf", root1);
        }
        else if(discriminant > 0)
        {

            root1 = ((-1)*b_coefficient + sqrt(discriminant))/(2*a_coefficient);
            root2 = ((-1)*b_coefficient - sqrt(discriminant))/(2*a_coefficient);
            printf("Roots of this equation are:");
            printf("%lf %lf", root1, root2);
        }
        else
        {
         printf("This equation has no roots");
        }


    }


    return 0;
}


