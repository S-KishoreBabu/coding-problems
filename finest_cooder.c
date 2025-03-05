#include<stdio.h>
#include<stdlib.h>
#include<string.h>



char* mergeAlternately(char * word1, char * word2){
    int n = strlen(word1)+strlen(word2);
    char *arr=(char*)malloc((sizeof(char)*n)+1);
    printf("arr[0] = %c",arr[0]);
    int j=0;
    int k=0;
    int i=0;
    while(i<n){
        
        if(j<strlen(word1)){
            arr[i]=word1[j];
            j++;
            i++;
        }
        printf("\n arr[%d] = %c",i,arr[i]);
        if(k<strlen(word2)){
            arr[i]=word2[k];
            k++;
            i++;

        }
        printf("\n arr[%d] = %c",i,arr[i]);
        
    }
    return arr;
}

int main(){
    char word1[] = "abc";
    char word2[] = "pqr";
    system("cls");
    printf("\n %s",mergeAlternately(word1, word2));
    return 0;
}