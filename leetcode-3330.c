#include <stdio.h>
#include<string.h>

int possibleStringCount(char* word) {
    int sum = 0;
    int front = 0;
    int back = 1;
    int count = 0;
    if(strlen(word)==1) return 1;
    while (back != strlen(word))
    {
        if(word[front] == word[back]){
            count++;
        }
        else{
            printf("\n coutn = %d\n",count);
            sum += count;
            count=0;
        }
        front++;
        back++;
    }
    printf("\n coutn = %d\n",count);
    sum+=count;
    
    return sum+1;
}

int main() {
    char word[] = "hellooo";
    int result = possibleStringCount(word);
    printf("%d\n", result);
    return 0;
}
