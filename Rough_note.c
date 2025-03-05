#include<stdio.h>
#include<stdlib.h>


int convertInt(char);
long toInt(char *s){
    long k = 1, num = 0,a;
    for(long i = strlen(s)-1;i>=0;i--){
        a = convertInt(s[i]);
        num=num+a*k;
        k = k * 2;
    }
    return num;
}

int getSize(int num){
    int count = 1, remainder;
    while(num!=1){
        remainder = num%2;
        count++;
        num = num/2;
    }
    return count;
}



char* toBinary(long num) {
    if (num == 0) return "0"; // Edge case for 0
    
    long size = getSize(num);
    char* string = (char*)malloc(size + 1); 
    long top = 0;

    while (num > 0) {
        string[top++] = (num % 2) + '0';  
        num /= 2;
    }
    
    string[top] = '\0'; 
    for (long i = 0; i < top / 2; i++) {
        char temp = string[i];
        string[i] = string[top - i - 1];
        string[top - i - 1] = temp;
    }

    return string;
}

int convertInt(char ch){
    int num = ch - '0';
    return num;
}

char* addBinary(char* a, char* b) {
    long num1 = toInt(a);
    long num2 = toInt(b);
    num1 += num2;
    return toBinary(num1);
}