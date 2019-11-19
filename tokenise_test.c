/*@Authors: Adrian Denis Coffey
 *          Michael Richard Smith 
 *          William Rodgers Orr 
 *          Tadhg Cecil Dolan
 * 
 * @Version: 0.1.3
 * @Best_Calculator_Ever - 11/2019
 * @Title: Tokeniser Program.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100
#define DATA_SIZE 1000

char * input(char * input);
char * tokeniser(char * str);
char * numberSweeper(char * str);
char * strtok(char * s, const char * delim);
void writeFile(char * data, char * output);
void printString(char * arr);
void arrayCopy(char * src, char * dest);

int main(void)
{
    //Declarations
    char str[MAX_SIZE];
    char out[MAX_SIZE];
    char data[DATA_SIZE];
    
    //Strings
    char * numbers;
    char * ops;
    const char s[5]="+-*/";
    
    //procedure call sequence:
    //Retrieve Input
    input(str);
    //Copy array for manipulation
    arrayCopy(str, out);
    
    /*DEBUG: Print contents of arrays
    printString(str);
    printString(out);
    */
    //numbers = strtok(str, s);
    numbers = tokeniser(str);
    while(numbers != NULL){printf("%s\n", numbers);numbers=strtok(NULL,s);}
    
    ops = numberSweeper(out);
    
    //printString(numbers);
    printString(ops);
    
    writeFile(data, (numbers));
}

char * input(char * str)
{
    printf("Enter Equation:::\n");
    scanf("%s", str);
    return str;
}

char * tokeniser(char * str)
{
    char * dest = str;
    char * src = str;
    
    while(*src)
    {
        if(*src == '+'||*src == '-'||*src == '*'||*src == '/'){src++; continue;}
            
        *dest++ = *src++;
    }
    *dest = '\0';
    return str;
}

char * numberSweeper(char * input)
{
    char* dest = input;
    char* src = input;

    while(*src)
    {
        if (isdigit(*src)||*src=='.') {src++; continue;}
        *dest++ = *src++;
    }
    *dest = '\0';
    return input;
}

void writeFile(char * data, char * output)
{
    FILE * fptr;
    fptr = fopen("input.txt", "rw");
    
    if(fptr == NULL)
    {
        printf("Unable to write to file.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Writing file");
    fgets(data, DATA_SIZE, stdin);
    fputs(data, fptr);
    fclose(fptr);
}

void arrayCopy(char * src, char * dest)
{
    for(int i=0; src[i] != '\0'; i++){dest[i] = src[i];}
}

void printString(char * arr)
{   
    printf("String...");
    for(int i=0; arr[i] !='\0'; i++)
    {
        printf("%c\n ", arr[i]);
    }
    printf("\n");
}
