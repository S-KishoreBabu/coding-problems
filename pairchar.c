//completed

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char *fruits[] = {
        "Apple",
        "Booooooks",
        "appaacche"
    };
    int arr[10];
    int size=-1;
    char t='(';
    int n,len;
    for (int i=0;i<3;i++){
        len=strlen(fruits[i]);
        n=0;
        for(int j=0;j<len;j++){
            if(fruits[i][j]==fruits[i][j+1]){
                if(t==fruits[i][j+1]){
                    n=n-1;
                }
                t=fruits[i][j];
                n=n+1;
            }
        }
        t='(';
        size=size+1;
        arr[size]=n;
    }
    printf("\n\n[ ");
    for(int k=0;k<=size;k++){
        printf("%d ",arr[k]);
    }
    printf(" ]");

    return 0;
}
