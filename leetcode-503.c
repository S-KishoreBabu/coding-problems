#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElements(int* nums, int numsSize, int* returnSize);


int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int circularArray[2*numsSize];

    for(int i = 0; i<numsSize;i++){
        circularArray[i] = nums[i];
        circularArray[i+numsSize] = nums[i];
    }

    int stack[numsSize];
    int top = -1;

    void displayStack(){
        printf("\n\n");
        for(int i = top; i>= 0; i--){
            printf(" %d \n",stack[i]);
        }
    }

    void push(int val){
        while(top!=-1 && stack[top]<=val){
            top--;
        }
        stack[++top]=val;
    }
    for(int i = 2*numsSize-1; i>= 0; i--){
        push(circularArray[i]);
        displayStack();
        if(i<numsSize){
            if(top-1 == -1){
                res[i] = -1;
            }
            else{
                res[i] = stack[top - 1];
                printf("--> %d", res[i]);
            }
        }
    }
    return res;
}



int main() {
    int nums[] = {2,10,12,1,11};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = nextGreaterElements(nums, numsSize, &returnSize);
    printf("\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}


