#include <stdio.h>// not completed yet
#include <string.h>
#include <math.h>
#include <stdlib.h>

// char* attach(const char *word,char ch){
//     //int x=strlen(word);
//     //printf("\n lendth =%d",x);
//     word=ch;
    // printf("attached : %s",word);
//     return word;
// }

int main() {

    char *s;
    printf("\nenter : ");
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    //s="he was good";
    s = realloc(s, strlen(s) + 1);
    int len,i=0;
    printf("\nsentence : %s && length = %d",s,strlen(s));
    char word[100];
    while(i!=strlen(s)){
            //printf("\n i = %d",i);
            word[]="";
            printf("\n%s",word);
            while(s[i]!=' '){
                len=strlen(word);
                word[len]=s[i];
                word[len + 1] = '\0';
                i=i+1;
                //len++;
            }
        printf("\n\nword = %s",word);
        i++;
    }
    return 0;
}