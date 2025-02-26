// Completed - Palindrome

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


char *removeAlphaNumeric(char *arr){
    char *string = (char*)malloc(strlen(arr)+1);
    int j=0;
    for(int i=0;i<strlen(arr);i++){
        if(isalpha(arr[i])){
            if(isupper(arr[i])){
                string[j]=tolower(arr[i]);
            }
            else{
                string[j]=arr[i];
            }
            j++;
        }
    }
    string[j]='\0';
    return string;
}

int main() {
    char *testString = "A man, a plan, a canal: Panama";
    if (isPalindrome(testString)) {
        printf("\"%s\" is a palindrome.\n", testString);
    } else {
        printf("\"%s\" is not a palindrome.\n", testString);
    }
    return 0;
}

bool isPalindrome(char* s) {

    if(strlen(s)==1){
        return true;
    }
    char *arr=removeAlphaNumeric(s);
    int j;
    for(int i=0;i<(strlen(arr)/2);i++){
        j=(strlen(arr)-i)-1;
        if(arr[i] != arr[j]){
            return false;
        }
    }
    return true;
}
