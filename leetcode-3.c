
//  * Completed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b){
    return (a>b)?a:b;
}


int lengthOfLongestSubstring(char* s) {
    int front = 0, back = 0, sum=0, total = 0;
    while(back!=strlen(s)){
        if(s[front]==s[back]){
            if(front == back){
                sum=1;
                back++;
            }else{
                front++;
                sum--;
            }
        }
        else{
            int flag =0,index;
            for(int i=front;i<back;i++){
                if(s[i]==s[back]){
                    flag = 1;
                    index = i;
                }
            }
            if(flag == 1){
                sum=1;
                front = index+1;
                back = front;
            }
            else{
                sum++;
                back++;
            }
        }
        total=max(sum,total);
    }

    return total;
}

int main(){
    char s[] = "uqinntq";
    printf("%d\n",lengthOfLongestSubstring(s));

    return 0;
}