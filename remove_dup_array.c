#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int* result = (int*)malloc(pricesSize * sizeof(int));
    int stack[pricesSize];
    int top = -1;

    for (int i = 0; i < pricesSize; i++) {
        while (top != -1 && prices[stack[top]] >= prices[i]) {
            result[stack[top]] = prices[stack[top]] - prices[i];
            top--;
        }
        stack[++top] = i;
    }

    while (top != -1) {
        result[stack[top]] = prices[stack[top]];
        top--;
    }

    *returnSize = pricesSize;
    return result;
}

int main(){
    
    system("cls");
    return 0;
}