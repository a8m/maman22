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

/*List: Errors*/
char *errorMsgs[] = {
    "Error: command %s does not exist\n",
    "Error: invalid %s\n",
    "Error: command too %s!!\n",
    "Error: variable %s does not exist!\n"
};

/*need to use a global variables*/
/*use extern in the other file in  .h or .c?*/
compleX a,b,c,d,e,f;

/*an array to store reference all complex numbers variabls*/
struct {
    char *name;
    compleX *var;
}storage[] = {
    {"A",&a},
    {"B",&b},
    {"C",&c},
    {"D",&d},
    {"E",&e},
    {"F",&f},
    {"0", NULL}
};

/*an array that store all cmd-complex function*/
/*PARAMS: {VAR, ARGS, SCALAR, NONE}*/
struct {
    char *name;
    void (*func)();
    int funcParam;
}cmd[] = {
    {"read_comp", read_comp, ARGS},
    {"print_comp", print_comp, NONE},
    {"not_valid", NULL, NONE}
};



int main()
{
    read_comp(&a, 1.00, 2.00);
    startUserInterface();
    print_comp(&a);
    return EXIT;
}

void startUserInterface()
{
    /*Print first welcome and help message*/
    printf("%s\n",LINE);
    printf("\t%s, %s\n",PROG_NAME, VERSION);
    printf("%s\n",LINE);
    
    printf("%s\n",START_MSG);
    /*end welcom and help message*/
    
    char command[MAX_COMMAND];
    char copyCommand[MAX_COMMAND];
    /*define and set state for system*/
    int state = WAIT_FOR_CMD_NAME;
    int paramState = NONE;
    int funcIndex = 0, varIndex = 0;
    int i;
    int c = 0;
    char ch;
    char *cmdName = "";
    char *varName = "";
    char *rest = "";
    
    /*get user input*/
    FOREVER{
        /*Scan all argument until you get enter-key*/
        for(i = 0; c != ENTER_KEY; i++){
            c = getchar();
            if (c == ENTER_KEY) break;
            ch = c;
            command[i] = ch;
            if(i > MAX_COMMAND){
                handleErrorInput("long", CMD_LONG);
                state = ERROR;
            }
        }
        if( i < MIN_COMMAND){
            handleErrorInput("short", CMD_LONG);
            state = ERROR;
        }
        c = 0;
        
        /*=================================COMMAND-NAME=======================*/
        if (state == WAIT_FOR_CMD_NAME) {
            /*copy command input*/
            strcpy(copyCommand, command);
            /*cmd name, variable name, rest parameters*/
            cmdName = strtok(command," ");
            varName = strtok(NULL,",");
            rest = strtok(NULL,"");
            
            /*through over all command list*/
            for(i=0; cmd[i].func != NULL; i++)
                if(strcmp(cmdName, cmd[i].name) == EQAULS)
                    break;
            
            if(cmd[i].func == NULL){
                state = ERROR;
                handleErrorInput(cmdName, CMD_NOT_EXIST);
            }
            else{
                state = WAIT_FOR_VAR;
                funcIndex = i;
            }
        }
        
        /*=================================END-COMMAND-NAME=======================*/
        
        /*=================================VAR-NAME=======================*/
        
        /*through over all variable list*/
        if (state == WAIT_FOR_VAR) {
            for(i=0; storage[i].var != NULL; i++){
               if(strcmp(varName, storage[i].name) == EQAULS)
                   break;
            }
            if(storage[i].var == NULL){
                state = WAIT_FOR_CMD_NAME;
                handleErrorInput(varName, VAR_NOT_EXIST);
            }else{
                paramState = stateAsCmd(funcIndex);
                state = WAIT_FOR_PARAMS;
                varIndex = i;
            }
        }
        
        /*=================================END-VAR-NAME=======================*/
        
            /*scan variables from input*/
            if(state == WAIT_FOR_PARAMS){
                switch (paramState) {
                    case NONE:
                    {
                        /*call command function with current variable*/
                        cmd[funcIndex].func(storage[varIndex].var);
                        break;
                    }
                        
                    case ARGS:
                    {
                        double a = atof(strtok(rest,","));
                        double b = atof(strtok(NULL,","));
                        cmd[funcIndex].func(storage[varIndex].var, a,b);
                        printf("Read to variable %s, two inputs: %.2f, %.2f\n", storage[varIndex].name, a, b);
                        break;
                    }
                }
                
            }
        
        
        
        
        
        
        
        
        
        
        /*clear command variable*/
        for (i = 0; i < MAX_COMMAND; i++) {
            command[i] = 0;
        }
        varName = "";
        rest = "";
        state = WAIT_FOR_CMD_NAME;
    }/*END FOREVER*/
    
}

/*return no. of state according cmd name*/
int stateAsCmd(int indexOfCmd)
{
    return cmd[indexOfCmd].funcParam;
}

/*handle error messages*/
void handleErrorInput(char *command, int msgIndex)
{
    printf("\n%s\n",LINE);
    printf(errorMsgs[msgIndex],command);
    printf("Try Again and Press Enter ->\n");
    printf("%s\n\n",LINE);
}


/*clear all char/string in buffer for new input*/
void clearBuffer()
{
    int c;
    c = getchar();
    while(c)
        if(c == ENTER_KEY)
            return;
        else
            c = getchar();
}
















