#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 20
int convertAlphatoNumeric(char);
int stack[max];
int top=-1;

void push(int val){
    if(top!=max-1){
        stack[++top]=val;
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

void display(){
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
}

void remdig(char *str,int size,int k){
    for(int i=1;i<size;i++){
        int n=convertAlphatoNumeric(str[i]);
        while(top!=-1 && k>0 && n<stack[top]){
            pop();
            k--;
        }
        push(n);
    }
    
    while(top!=-1 && k>0){
        pop();
        k--;
    }
}

void removeDigits(char *str,int size,int k){
    int n;
    if(str[0]=='-'){
        remdig(str,size,k);
        return;
    }
    for(int i=0;i<size;i++){
        n=convertAlphatoNumeric(str[i]);
        while(top!=-1 && k>0 && n<stack[top]){
            pop();
            k--;
        }
        push(n);
    }
    while(top!=-1 && k>0){
        pop();
        k--;
    }
}

int convertAlphatoNumeric(char ch){
    if(ch >= '0' && ch <= '9'){
        return ch - '0';
    }
}

int main(){
    char str[]="1432219";
    int len=strlen(str);
    system("cls");
    removeDigits(str,len,3);
    display();
    return 0;

}