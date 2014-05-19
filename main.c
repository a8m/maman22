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
    "*ERROR: command %s does not exist\n",
    "*ERROR: invalid %s\n",
    "*ERROR: command too %s!!\n",
    "*ERROR: variable %s does not exist!\n",
    "*ERROR: Low number of %s\n",
};

char *systemMsgs[] = {
    "Please enter valid function name and suitable parameters\nUsage [function_name] [variable],[parameters:optionl]",
    "Available functions:\nread_comp           [complex number],[parameter],[parameter]\nprint_comp          [complex number]\nadd_comp            [complex number],[complex number]\nsub_comp            [complex number]\nmult_comp_real      [complex number],[scalar]\nmult_comp_img       [complex number],[scalar]\nmult_comp_comp      [complex number],[complex number]\nabs_comp            [complex number]\nhalt                [none]",
    "INFORM: Program halted, press enter [ret] key to exit..."
};

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
struct {
    char *name;
    void (*func)();
    int funcParam;
}cmd[] = {
    {"read_comp", read_comp, ARGS},
    {"print_comp", print_comp, NONE},
    {"add_comp", add_comp, VAR},
    {"sub_comp", sub_comp, VAR},
    {"mult_comp_real", mult_comp_real, SCALAR},
    {"mult_comp_img", mult_comp_img, SCALAR},
    {"mult_comp_comp", mult_comp_comp, VAR},
    {"abs_comp", abs_comp, NONE},
    {"not_valid", NULL, NONE}
};



int main()
{
    startUserInterface();
    return EXIT;
}

void startUserInterface()
{
    char command[MAX_COMMAND];
    /*define and set state for system*/
    int state = WAIT_FOR_CMD_NAME, paramState = NONE,
    funcIndex = 0, varIndex = 0;
    int i,c = 0;
    char ch;
    char *cmdName = "", *varName = "", *rest = "";
    
    /*Print first welcome and help message*/
    printf("%s\n",LINE);
    printf("\t%s, %s\n",PROG_NAME, VERSION);
    printf("%s\n",LINE);
    
    printf("%s\n\n",systemMsgs[START]);
    printf("%s\n%s\n",systemMsgs[HELP],LINE);
    /*end welcom and help message*/
    
    /*get user input*/
    FOREVER{
        printf("-> ");
        /*Scan all argument until you get enter-key*/
        for(i = 0; c != ENTER_KEY; i++){
            c = getchar();
            if (c == ENTER_KEY) break;
            ch = c;
            command[i] = ch;
            if(i > MAX_COMMAND){
                handleErrorInput("long", CMD_LONG);
                state = ERROR;
                clearBuffer();
                break;
            }
        }
        
        /*if user enter halt, make sure..and stop running*/
        if (strcmp(command, "halt") == EQAULS || strcmp(command, "halt") == TRUE){
            printf("%s",systemMsgs[HALT]);
            {
                int decision = getchar();
                if (decision == ENTER_KEY)
                    break;
                else
                    state = ERROR;
            }
        }
        /*add min-length command validation*/
        if( i < MIN_COMMAND){
            handleErrorInput("short", CMD_LONG);
            state = ERROR;
        }
        c = 0;
        
        /*=================================CHECK-COMMAND=========================*/
        
        if (state == WAIT_FOR_CMD_NAME) {
            
            int commandLength, funcLength, varLength;
            commandLength = strlen(command);
            
            cmdName = strtok(command," ");
            funcLength = strlen(cmdName);
            
            if(commandLength - funcLength >= 2){
                varName = strtok(NULL,",");
                varLength = strlen(varName);
                
                if(commandLength - funcLength - varLength >= 2)
                    rest = strtok(NULL,"");
            }else{
                state = ERROR;
                handleErrorInput("parameters", LOW_ARGS);
            }
        }
        
        /*=================================END-CHECK-COMMAND=======================*/
        
        /*=================================FIND-FUNCITON==========================*/
        if (state != ERROR) {
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
        
        /*=================================END-FIND-FUNCTION====================*/
        
        /*=================================VAR-NAME=============================*/
        
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
                        int restLength = strlen(rest);
                        double a,b;
                        if (restLength < MIN_ARGS) {
                            state = ERROR;
                            handleErrorInput("parameters", LOW_ARGS);
                            break;
                        }
                        a = atof(strtok(rest,","));
                        b = atof(strtok(NULL,","));
                        printf("%s", rest);
                        cmd[funcIndex].func(storage[varIndex].var, a,b);
                        printf("Read to variable %s, two inputs: %.2f, %.2f\n", storage[varIndex].name, a, b);
                        break;
                    }
                    
                    case VAR:
                    {
                        int len;
                        len = strlen(rest);
                        if(len > 1)
                            handleErrorInput("number of arguments after variable", INVALID_ARGS);
                        else{
                            for(i=0; storage[i].var != NULL; i++){
                                if(strcmp(rest, storage[i].name) == EQAULS)
                                    break;
                            }
                            if(storage[i].var == NULL)
                                handleErrorInput(rest, VAR_NOT_EXIST);
                            else
                                cmd[funcIndex].func(storage[varIndex].var, storage[i].var);
                        }
                        
                        break;
                    }/*end param case */
                        
                    case SCALAR:
                    {
                        int len;
                        len = strlen(rest);
                        if(len > MAX_SCALAR)
                            handleErrorInput("number of arguments after variable", INVALID_ARGS);
                        else{
                            char isDigitFlag = rest[0];
                            if(!isDigitFlag){
                                handleErrorInput("scalar argument, inster real number please", INVALID_ARGS);
                                break;
                            }else{
                                double num = atof(rest);
                                cmd[funcIndex].func(storage[varIndex].var, num);
                            }
                        }
                    
                        break;
                    }/*end scalar case*/
                        
                        
                }/*end switch statement*/
                
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
    printf("%s\n\n",LINE);
}


/*clear all char/string in buffer for new input*/
void clearBuffer()
{
    int c;
    c = getchar();
    while(c)
        if(c == ENTER_KEY){
            return;
        }
        else
            c = getchar();
}
















