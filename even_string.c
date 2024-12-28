#include<stdio.h>// not completed (eliminate the charecters from given string to given prefix and suffx word by  same prefix  charecter and suffix charecter in both strings)
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
