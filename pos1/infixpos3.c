#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <sys/types.h>
#include <regex.h>
#include <string.h>

#define MaxStack 50
#define RogueValue -99

 
typedef struct Stack {

       int top;

       char ST[MaxStack];

  }Stack;

 
Stack S;

int convertToPostfix(char infx[], char pofx[]);

char push(char ch);

char pop();

int isEmpty();

int precedence(char ch);

void printPostfix(char pofx[], int n);

int evaluate(char infx[], int size);

int main() {

     

    FILE * in = fopen("input.txt", "r");

    FILE * out = fopen ("answers.txt", "w");

     

    char infx[50],pofx[50];

    S.top = 0;

    fscanf(in, "%s", infx);


           convertToPostfix(infx, pofx);

           fprintf(out, "Infix Expression: %s\n", infx); 

           fprintf(out, "\nPostfix Expression: %s\n\n\n",pofx);

fclose(in);

fclose(out);

       

system("pause");

return 0;   

}

 
int convertToPostfix(char infx[], char pofx[]){

     

    char ch;

    int  i= 0, k = 0;

     

    while((ch = infx[i++]) != '\0') {  

         if( ch == '(')

             push(ch);

              

        else if(ch >='0' && ch <= '9')

             pofx[k++]=ch;

              

        else if( ch == ')') {

                 while( S.ST[S.top] != '(')

                    pofx[k++]=pop();

                         

                    ch = pop();

        }       

        else {     

            while( precedence(S.ST[S.top]) >= precedence(ch) )

                  pofx[k++]=pop();

                         

                    push(ch);

        }

    }

   

    while( S.ST[S.top] != -1)     /* Pop from stack till empty */

        pofx[k++]=pop();

        return k;

} 

      

char push(char ch) {

      if (S.top == MaxStack - 1){

               printf("Stack overflow\n");

               return 1;

            }

    S.ST[++S.top] = ch;

}

  

char pop() { 

     if (isEmpty(S))

          return RogueValue;    

                          

    char popped = S.ST[S.top];

     --(S.top);

           return popped;

}

 

int isEmpty(){

    return(S.top == -1);

}

  

int precedence(char ch){

    if ( ch == '(') return 1;

    if ( ch == '+' || ch == '-') return 2;

    if ( ch == '*' || ch == '/' || ch == '%') return 3;

   

    if ( ch == '^') return 4;

    if ( ch == 'f') return 5;


}

 

int evaluate (char pofx[], int size){

    int i, a , b, c, n;

    Stack temp;

     

    S.top = -1; //init Stack

     

    for(i = 0; i < size; i++){

          if( pofx[i] <= '9' && pofx[i] >= '0')

                push (pofx[i] - '0');

           

          else {

              b = pop();

              a = pop();

               

              if (pofx[i] == '+')

                      c = a + b;

                           

              else if (pofx[i] == '-')

                      c = a - b;

              else if (pofx[i] == '*')

                      c = a * b;

              else if (pofx[i] == '/')

                      c = a / b;

              else if (pofx[i] == '%')

                      c = a % b;

              else if (pofx[i] == '^'){

                   c = 1.0;

                   for(n = 1; n <= b; n++)

                         c = c*a;

              }

              else if (pofx[i] == 'f'){

                   for(n = pofx[i]; n > 0; n--)

                          c = c*n;

              }

         

              push(c);

         }

    }

    return pop();

}
