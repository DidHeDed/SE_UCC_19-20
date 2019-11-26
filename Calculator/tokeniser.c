/*@Authors: Adrian Denis Coffey
 *          Michael Richard Smith 
 *          William Rodgers Ohr 
 *          Tadhg Cecil Dolan
 * 
 * @Version: 0.3
 * @Best_Calculator_Ever - 11/2019
 * @Title: Tokeniser Program.
 */
//HEADER INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Set the upper limit for char[]
#define max_size 1000

//declare string tokeniser - builtin
char * strtok(char *str, const char *delims);

//single procedure program
int main(void)
{
    //declare string arrays.
    char str[max_size];
    char str1[max_size];

    //temp string pointers for manipulation
    char * numbers, * ops;

    //input prompt
    printf("Enter Equation:::\n");

    //input stream stored in string array 0
    scanf("%s", str);
    
    //copy string[]
    strcpy(str1, str);
    
    //open file in write only mode
    FILE *fp = fopen("input.txt", "w");

    //check file exists.
    if(fp == NULL)
    {
        //ERROR MESSAGE if unable to write to file
        printf("Unable to write to file.\n");
        //exit on failure
        exit(EXIT_FAILURE);
    }
    else
    {
        //Notice for file write operation success
        printf("\nWriting file\n");
        //tokenise string based on delimiters:result = digits.
        numbers = strtok(str, "-+/*=");
        
        //run through string and print digits to file.
        while(numbers != NULL)
        {
            //delimiter ',' added to digits.
            fprintf(fp, "%s\n", numbers);
            numbers = strtok(NULL,"-+ /*=()");
        }

        //tokenise string based on digits and decimal = operators
        ops = strtok(str1, "0123456789.");
        
        //run through string copy and print operators to file
        while(ops != NULL)
        {   
            //delimiter " " added to operators list
            fprintf(fp, "%s\n", ops);
            ops = strtok(NULL, "0123456789.");
        }
        
        //close file
        fclose(fp);
    }
    return 0;
}
