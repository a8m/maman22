/*
 * =========================================================================================
 * name        : mmn_22/main.c
 * author      : Ariel Mashraki, ID 301......
 * email       : ariel@.....
 * description : description....
 * =========================================================================================
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

/*#define ....*/

typedef struct compleX{
    double a,b;
} compleX;

/*extern global variables*/
extern compleX a,b,c,d,e,f;

/* >>>>>>>>>>>>>>>>>>>>>>>>> FUNCTION DECLARTION >>>>>>>>>>>>>>>>>>>>>>>>> */

/*
 *set compleX variable with
 *params: pointer to compleX, double a, double b
 */
void read_comp(compleX *cp, double a, double b);


/*
 *print compleX variable
 *params: pointer to complex
 *example: (a+bi) ===> 2.31 + 4.05i
 */
void print_comp(compleX *cp);

/*add two complex numbers
 *and print the sum of them
 */
void add_comp(compleX *cpA, compleX *cpB);

/*subtract two complex numbers
 *and print the sum of them
 */
void sub_comp(compleX *cpA, compleX *cpB);

/*multiple complex number with real number scalar
 *argument and print the result*/
void mult_comp_real(compleX *cp, double scalar);

/*multiple complex number with img number scalar
 *argument and print the result*/
void mult_comp_img(compleX *cp, double scalar);

/*multiple complex number with complex number
 *argument and print the result*/
void mult_comp_comp(compleX *cpA, compleX *cpB);


/*return the absolue value of complex number*/
void abs_comp(compleX *cp);



#endif /* COMPLEX_H_ */
