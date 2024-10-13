#include<stdio.h>// not completed
#include<string.h>
#include<strings.h>

int main(){
    char string[]="nothing";
    char prefix[]="brono";
    char suffix[]="ingenious";
    for(int i=strlen(prefix)+1;i>0;i--){
        printf("\n a: %c  b: %c ",string[i],prefix[i]);
    }
    return 0;
}