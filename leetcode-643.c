#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


int getSum(int *nums,int k){
    int sum = 0;
    for(int i = 0;i<k;i++){
        sum +=nums[i];
    }
    return sum;
}

int max(int a,int b){
    return (a>b)?a:b;
}

double slidingWindow(int* nums, int numsSize, int k) {
    int sum = getSum(nums,k);
    int total = sum;

    int front = 0;
    int back = k;

    while(back!=numsSize){
        sum = sum - nums[front] + nums[back];
        front++;
        back++;
        total = max(total,sum);
    }
    return total;
}