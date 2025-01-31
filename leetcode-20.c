#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char stack[100];
int top=-1;

void push(char ch){
    stack[++top]=ch;
}

char pop(){
    char ch=stack[top];
    top--;
    return ch;
}

bool isValid(char* s) {
    for(int i = 0; i<strlen(s);i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            push(s[i]);
        }
        else{
            if((stack[top]=='(' && s[i]==')') ||
            (stack[top]=='[' && s[i]==']')||
            (stack[top]=='{' && s[i]=='}')){
                pop();
            }     
        }
    }
    if(top==-1){
        return true;
    }
    return false;
}

int main(){
    char s[] = "([])";
    system("cls");
    if(isValid(s)){
        printf("%s is a valid expression\n", s);
    }

    return 0;
}