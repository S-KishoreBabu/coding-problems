#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int strStr(char* haystack, char* needle) {
    int j=0;
    int start=-1;
    if(strlen(needle)>strlen(haystack)){
        return -1;
    }
    for(int i = 0; i<strlen(haystack); i++){
        if(haystack[i] == needle[j]){
            if(j==0){
                start = i;
                printf("\n start is %d",start);
            }
            j++;
            if(j== strlen(needle)){
                return start;
            }
        }
        else{
            if(j>0){
                j=0;
                i = start+1;
                start = -1;
            }
        }
    }
    return start;
}

int main(){
    char haystack[] = "mississippi";
    char needle[] =       "issip";
    system("cls");
    printf("\n Result : %d",strStr(haystack,needle));
    return 0;
}