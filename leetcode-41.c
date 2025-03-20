//** Not completed - Merging the two sorted array
#include<stdio.h>
#include<stdlib.h>



int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); 
}

int firstMissingPositive(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int sum = 0;
    int a = nums[0];
    int s = 0;
    
    for(int i = 1;i<numsSize;i++){
        printf("\n a+1 = %d ",a+1);
        if(nums[i]==a+1){
            a = nums[i];
            s=nums[i];
        }
        else{
            return a+1;
        }
    }
    if(s==nums[numsSize-1]){
        return nums[numsSize-1]+1;
    }
    return sum;
}
int main(){
    int arr[] = {7,8,9,11,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = firstMissingPositive(arr,n);
    printf("\n%d",result);

    return 0;
}