#include <stdio.h>

// Function declaration
int search(int* nums, int numsSize, int target);
int findMin(int*, int);

int findMin(int* nums, int numsSize) {
    int mid,l = 0, r = numsSize -1;
    while(l+1<r){
        mid = l+(r-l)/2;
        if(nums[mid]>nums[r]) l = mid;
        else r = mid;
    }
    return (nums[l]<nums[r])?l:r;
}

int search(int* nums, int numsSize, int target) {
    int x,low = 0, high = numsSize-1,sep = findMin(nums,numsSize);
    if(numsSize==1) return (nums[0]==target)?0:-1;
    int binarySearch(int left, int right, int target){
        int mid = -1;
        while(left <= right){
            mid = left + (right - left)/2;
            printf("\n test (mid) = %d",mid);
            if(nums[mid] == target) return mid;
            else if(nums[mid]<target) left = mid+1;
            else right = mid - 1;
        }
        return -1;
    }
    if(sep == 0) return binarySearch(low,high,target);
    x = binarySearch(low,sep-1,target);
    printf("\n high = %d",sep);
    return (x != -1)?x:binarySearch(sep,high,target);
}

int main() {
    // Example input
    int nums[] = {4,5,6,7,0,1,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 2;

    // Call your function
    int result = search(nums, numsSize, target);

    // Print the result
    printf("\n %d\n", result);

    return 0;
}

