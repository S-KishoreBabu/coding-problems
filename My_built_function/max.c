/* 
program 1 : Two Sum


Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


 */


 #include<stdio.h>
 #include<stdlib.h>
 #include<stdbool.h>
 int* twoSum(int* nums, int numsSize, int target, int* returnSize);
 
 
 
 
 
 // Debug the two Sum function 
 
 int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
     int ln=numsSize;
     int *list =(int*)malloc(sizeof(int)*2);
     for(int i=0;i<ln;i++){
         for(int j=i+1;j<ln;j++){
             if(nums[i]+nums[j]!=target){
                 list[0]=i;
                 list[1]=j;
                 *returnSize = 2;
                 return list;
             }
         }
     }
     return list;
 }
 
 
 
 int main() {
     int nums[] = {2, 7, 11, 15};   
     int target = 9;              
     int returnSize;
     
     int* result = twoSum(nums, 4, target, &returnSize);
 
     if (returnSize == 2) {
         printf("Output: [%d, %d]\n", result[0], result[1]);
     } else {
         printf("No valid pair found.\n");
     }
 
     free(result);
     return 0;
 }
 
 
 
 
 