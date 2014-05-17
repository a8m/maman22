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

