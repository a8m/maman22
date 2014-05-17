/*
 * =========================================================================================
 * name        : mmn_22/main.c
 * author      : Ariel Mashraki, ID 301......
 * email       : ariel@.....
 * description : description....
 * =========================================================================================
 */

#include "complex.h"
#include "common.h"

/*all functions in header file*/

void read_comp(compleX *cp, double a, double b)
{
    (*cp).a = a;
    (*cp).b = b;
}


/* add complex number name to*/
void print_comp(compleX *cp)
{
    printf("%.2f + %.2fi\n", (*cp).a, (*cp).b);
}

/*calculate the sum between two complex numbers*/
void add_comp(compleX *cpA, compleX *cpB)
{
    compleX temp;
    temp.a = (*cpA).a + (*cpB).a;
    temp.b = (*cpA).b + (*cpB).b;
    printf("The result of the addition:\n");
    print_comp(&temp);
}

/*calculate the subtract between two complex numbers
 *and print the sum
 */
void sub_comp(compleX *cpA, compleX *cpB)
{
    compleX temp;
    temp.a = (*cpA).a - (*cpB).a;
    temp.b = (*cpA).b - (*cpB).b;
    
    printf("The result of the subtraction:\n");
    print_comp(&temp);
}

/*multiple complex number with scalar
 *argument and print the result*/
void mult_comp_real(compleX *cp, double scalar)
{
    compleX temp;
    temp.a = (*cp).a * scalar;
    temp.b = (*cp).b * scalar;
    
    printf("The result of the multiplication with scalar:\n");
    print_comp(&temp);

}


/*multiple complex number with img number scalar
 *argument and print the result*/
void mult_comp_img(compleX *cp, double scalar)
{
    compleX temp;
    temp.a = (*cp).a * scalar;
    temp.b = -(*cp).b * scalar;
    
    printf("The result of the multiplication with img scalar:\n");
    if (temp.a < 0)
        printf("%.2f + (%.2fi)\n", temp.b, temp.a);
    else
        printf("%.2f + %.2fi\n", temp.b, temp.a);
}


/*multiple complex number with complex number
 *argument and print the result*/
void mult_comp_comp(compleX *cpA, compleX *cpB)
{
    compleX temp;
    temp.a = ((*cpA).a * (*cpB).a) - ((*cpA).b * (*cpB).b);
    temp.b = ((*cpA).a * (*cpB).b) + ((*cpA).b * (*cpB).a);
    
    printf("The result of the multiplication of two complex numbers:\n");
    print_comp(&temp);
}


/*return the absolue value of complex number*/
void abs_comp(compleX *cp)
{
    double absolue = sqrt( (pow((*cp).a, 2)) + (pow((*cp).b, 2)) );
    printf("The Absolute value of your variable is: %.2f\n", absolue);
}









