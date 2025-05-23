#include<stdio.h>

int shipWithinDays(int* weights, int weightsSize, int days);

int getHigh(int *nums,int numsSize){
    int sum = 0;
    for(int i = 0; i< numsSize;i++){
        sum+=nums[i];
    }
    return sum;
}

int getAns(int mid,int *nums,int n){
    int count = 0, sum = 0;
    for(int i = 0; i<n;i++){
        sum+=nums[i];
        if(sum>mid){
            sum = 0;
            i--;
            count++;
        }
    }
    return count;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int shipWithinDays(int* weights, int weightsSize, int days) {
    int answer,mid,high = getHigh(weights, weightsSize);
    int low = findMax(weights, weightsSize);
    while(low<high){
        mid = low+(high-low)/2;
        answer = getAns(mid, weights, weightsSize);
        if(answer<days){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return high;
}


int main() {
    int weights[] = {1,2,3,1,1};
    int weightsSize = sizeof(weights) / sizeof(weights[0]);
    int days = 4;
    int result = shipWithinDays(weights, weightsSize, days);
    printf("%d\n", result);
    return 0;
}

