#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    int* res = (int*)malloc(sizeof(int) * temperaturesSize);
    int stack[temperaturesSize],indexStack[temperaturesSize], top = -1;

    void push(int temp_val, int index_val){
        while(top != -1 && stack[top] <= temp_val){
            top--;
        }
        stack[++top] = temp_val;
        indexStack[top] = index_val;
    }

    for(int i = temperaturesSize-1; i>= 0;i--){
        push(temperatures[i],i+1);
        res[i] = (top == 0)?0:indexStack[top-1] - indexStack[top];
    }
    return res;
}

int main() {
    int temperatures[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int temperaturesSize = sizeof(temperatures) / sizeof(temperatures[0]);
    int returnSize;

    int* result = dailyTemperatures(temperatures, temperaturesSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
