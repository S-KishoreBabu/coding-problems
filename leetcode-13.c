#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool isvalid(char,char);
int romansToNumeric(char );

int romansToNumeric(char a){
    switch(a){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
}

bool isvalid(char a,char b){
    int x=romansToNumeric(a);
    int y=romansToNumeric(b);
    printf("\n\nx = %d y = %d",x,y);
    if(x>=y){
        return true;
    }
    return false;
}

int romanToInt(char* s) {
    int stack[strlen(s)];
    int top=-1;
    int max=0;
    int sum=0;
    for(int i=0;i<strlen(s);i++){
        if(i==0){
            stack[++top]=s[i];
            sum=romansToNumeric(s[i]);
            printf("\n sum== %d",sum);
        }
        else{
            if(isvalid(stack[top],s[i])){
                printf("\n ch= %c",s[i]);
                stack[++top]=s[i];
                sum+=romansToNumeric(s[i]);
                printf("\n sum= %d",sum);
            }
            else{
                printf("\n ch==> %c",s[i]);
                sum-=romansToNumeric(stack[top]);
                sum+=(romansToNumeric(s[i])-romansToNumeric(stack[top]));
                stack[++top]=s[i];
                
            }
        }
    } 
    return sum; 
}

int main(){
    char str[]="III";
    system("cls");
    int result = romanToInt(str);
    printf("\n result = %d ",result);
}