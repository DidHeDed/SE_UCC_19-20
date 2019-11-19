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

//String manipulation procedures
char * input(char * input);
char * numberSweeper(char * str);
char * strtok(char * s, const char * delim);
char * output_txt(char * arr);

//void procedures
void writeFile(char * d1, char * d2);
void printString(char * arr);
void arrayCopy(char * src, char * dest);


int main(void)
{
    //Declarations
    char str[MAX_SIZE];
    char out[MAX_SIZE];
    char data[MAX_SIZE];
    
    //Strings
    char *numbers, *ops;
    const char s[5]="+-*/";
    
    //procedure call sequence:
    //Retrieve Input
    input(str);
    //Copy array for manipulation
    arrayCopy(str, out);
    
    //Tokenise: Numbers
    numbers = strtok(str, s);
    printf("[");
    while(numbers != NULL)
    {
    printf("%s'", numbers);numbers=strtok(NULL,s);
    }
    printf("]");

    //Tokenise: Operators
    ops = numberSweeper(out);
    
    //printString(numbers);
    printString(ops);
    
    writeFile(data, ops);
    
    
}
char * input(char * str)
{
    printf("Enter Equation:::\n");
    scanf("%s", str);
    return str;
}

char * numberSweeper(char * input)
{
    char* dest = input;
    char* src = input;

    while(*src)
    {
        if (isdigit(*src)||*src=='.'||*src==NULL) {src++; continue;}
        *dest++ = *src++;
    }
    *dest = NULL;
    return input;
}

void writeFile(char * d1, char * d2)
{
    char data[MAX_SIZE][MAX_SIZE];
    FILE * fptr = fopen("input.txt", "w");
    
    if(fptr == NULL)
    {
        printf("Unable to write to file.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Writing file");
        fwrite(data, sizeof(char *), sizeof(data), fptr);
        fclose(fptr);
    }
    return(0);
}

void arrayCopy(char * src, char * dest)
{
    for(int i=0; src[i] != '\0'; i++){dest[i] = src[i];}
}

void printString(char * arr)
{   
    printf("[");
    for(int i=0; arr[i] !='\0'; i++)
    {
        printf("%c", arr[i]);
    }
    printf("]");
}

char * output_txt(char * arr)
{
    char * output[MAX_SIZE];
    output[0] = "[";
    int i=1;
    for(i; arr[i] != '\0'; i++)
    {
        output[i]= arr[i];
    }
    output[i]="]";
    return output;
}
