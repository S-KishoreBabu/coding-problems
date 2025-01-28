#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int index = 1; // Index to place the next valid element
    int count = 1; // Count occurrences of the current number

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            // If the current number is the same as the previous one, increment count
            count++;
        } else {
            // Reset count for a new number
            count = 1;
        }

        // Allow the number if it appears at most twice
        if (count <= 2) {
            nums[index++] = nums[i];
        }
    }

    return index;
}

int main(){
    
    system("cls");
    return 0;
}