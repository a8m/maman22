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



#endif /* COMPLEX_H_ */
