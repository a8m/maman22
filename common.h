/*
 * =========================================================================================
 * name        : mmn_22/main.c
 * author      : Ariel Mashraki, ID 301......
 * email       : ariel@.....
 * description : description....
 * =========================================================================================
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*read.. should i used them?*/

/* >>>>>>>>>>>>>>>>>>>>>>>>> GLOBAL DEFINE >>>>>>>>>>>>>>>>>>>>>>>>> */
#define EXIT           0
#define PROG_NAME      "COMPLEX CALCULATOR"
#define VERSION        "MMN_22 v0.0.01_301448742"
#define LINE           "============================================================="
#define EQAULS         0
#define COMMA          ","

/* >>>>>>>>>>>>>>>>>>>>>>>>> GLOBAL ENUMS >>>>>>>>>>>>>>>>>>>>>>>>> */
enum inputValidation   {INVALID, VALID};
enum returnFunction    {FALSE, TRUE};
enum inputState        {WAIT_FOR_CMD_NAME, WAIT_FOR_VAR, WAIT_FOR_PARAMS, ERROR};
enum inputParams       {VAR, ARGS, SCALAR, NONE};
enum spaceFlags        {BEFORE, AFTER};
/*Errors and System msgs*/
enum errorMsgs         {CMD_NOT_EXIST, INVALID_ARGS, CMD_LONG, VAR_NOT_EXIST, LOW_ARGS};
enum systemMsgs        {START, HELP, HALT};

/* >>>>>>>>>>>>>>>>>>>>>> INPUT OUTPUT MANAGER >>>>>>>>>>>>>>>>>>>>>> */
void startUserInterface();
void handleErrorInput(char *command, int msgIndex);
void clearBuffer();
int stateAsCmd(int indexOfCmd);

/* prints simple UI that manages inputed commands */
#define FOREVER         for(;;)
#define MAX_COMMAND     30
#define MIN_COMMAND     4
#define MAX_SCALAR      4
#define SPACE_KEY       32
#define ENTER_KEY       10
#define MAX_SPACE_BEFORE 1
#define MAX_SPACE_AFTER 2
#define MIN_ARGS        3


#endif
