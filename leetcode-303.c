int pivotIndex(int* nums, int numsSize) {
    for(int i = 1; i<numsSize; i++){
        nums[i] +=nums[i-1];
    }

    int front = 0 ,back,b = nums[numsSize-1];
    for(int i = 0; i < numsSize;i++){
        back = b-nums[i];
        if(front == back ) return i;
        front = nums[i];
    }

    return -1;
}