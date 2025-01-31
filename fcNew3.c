#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define max 20
int convertAlphatoNumeric(char);
int stack[max];
int top=-1;
int chtop=-1;
char stackch[max];

void push(int val){
    if(top!=max-1){
        stack[++top]=val;
    }
    else{
        printf("Stack is full\n");
    }
}

void pushch(int val){
    if(chtop!=max-1){
        stackch[++chtop]=val;
    }
    else{
        printf("Stack is full\n");
    }
}

int pop(){
    if(top!=-1){
        int x = stack[top];
        top--;
        return x;
    }
    printf("\n Stack is Empty");
}

char popch(){
    if(chtop!=-1){
        char x = stackch[chtop];
        chtop--;
        return x;
    }
    printf("\n Stack is Empty");
}

void display(){
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

char * convert_to_postfix(char *str, int size) {
    char *output = (char *)malloc(size * sizeof(char));
    int j = 0;

    for (int i = 0; i < size; i++) {
        if (isalnum(str[i])) {
            output[j++] = str[i];
        } else if (str[i] == '(') {
            pushch(str[i]);
        } else if (str[i] == ')') {
            while (chtop != -1 && stackch[chtop] != '(') {
                output[j++] = popch();
            }
            popch(); 
        } else {
            while (chtop != -1 && precedence(stackch[chtop]) >= precedence(str[i])) {
                output[j++] = popch();
            }
            pushch(str[i]);
        }
    }

    while (chtop != -1) {
        output[j++] = popch();
    }
    output[j] = '\0'; // Null-terminate the output string
    return output;
}

int postfixEvaluation(char *str, int size){
    for(int i=0;i<size;i++){
        if(isalnum(str[i])){
            push(str[i]-48);
        }
        else{
            int a=pop();
            int b=pop();
            switch(str[i]){
                case '+':
                    push(b+a);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '*':
                    push(b*a);
                    break;
                case '/':
        }
    }
}

void dispValue(){
    }

void calculation_postfix(char *str,int size){
    int i=0;
    while(i<size){
        if(isdigit(str[i])){
            push(str[i]-48);
        }
        else{
            int a = pop();
            int b = pop();
            switch(str[i]){
                case '+':
                    push(a+b);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '*':
                    push(a*b);
                    break;
                case '/':
                    push(b/a);
                    break;
                case '%':
                    push((int)(b%a));
                    break;
                case '^':
                    push(pow(b,a));
                    break;
                 
            }

        }
        i++;
    }
}

void dispValue(){
    printf("\n Value of expression is %d",pop());
}

int main(){
    char str[]="23*54*+9-";
    system("cls");
    printf("Enter the postfix expression: ");
    scanf("%s",&str);
    int size = strlen(str);
    calculation_prefix(str,size);
    dispValue();
    return 0;
}