#include <stdio.h>
#include<stdlib.h>

int* backElements(int* nums, int numsSize, int* returnSize);
int* frontElements(int* nums, int numsSize, int* returnSize);
int* backElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int stack[numsSize];
    int istack[numsSize];
    int top = -1;

    void displayStack(){
        printf("\n\n");
        for(int i = top; i>= 0; i--){
            printf(" %d \n",stack[i]);
        }
    }

    void push(int val, int index_val){
        while(top!=-1 && stack[top]>=val){
            top--;
        }
        stack[++top]=val;
        istack[top] = index_val;
    }

    for(int i =numsSize-1; i>= 0; i--){
        push(nums[i],i);
        displayStack();
        if(top == 0){
            res[i] = numsSize-1;
        }
        else{
            res[i] = (istack[top - 1])-1;
            printf("--> %d", res[i]);
        }
    }
    return res;
}

int* frontElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int stack[numsSize];
    int istack[numsSize];
    int top = -1;

    void displayStack(){
        printf("\n\n");
        for(int i = top; i>= 0; i--){
            printf(" %d \n",stack[i]);
        }
    }

    void push(int val, int index_val){
        while(top!=-1 && stack[top]>=val){
            top--;
        }
        stack[++top]=val;
        istack[top] = index_val;
    }

    for(int i =0; i<numsSize; i++){
        push(nums[i],i);
        displayStack();
        if(top == 0){
            res[i] = 0;
        }
        else{
            res[i] = (istack[top - 1])+1;
            printf("--> %d", res[i]);
        }
    }
    return res;
}


int largestRectangleArea(int* heights, int heightsSize) {
    int returnSize,sum=0;
    int* front = frontElements(heights, heightsSize, &returnSize);
    int* back = backElements(heights, heightsSize, &returnSize);
    int arr[heightsSize];
    for(int i = 0; i<heightsSize; i++){
        arr[i] = ((back[i]-front[i])+1)*heights[i];
    }
    int max = arr[0];
    for (int i = 1; i < heightsSize; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int heightsSize = sizeof(heights) / sizeof(heights[0]);

    int result = largestRectangleArea(heights, heightsSize);
    printf("\n -> %d\n", result);

    return 0;
}
