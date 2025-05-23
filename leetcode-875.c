#include <stdio.h>
#include <math.h>
int minEatingSpeed(int* piles, int pilesSize, int h);

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int hours(int *arr, int n, int hour){
    int sum = 0;
    double x;
    for(int i=0;i<n;i++){
        x = (double)arr[i]/hour;
        sum += (int)ceil(x);
    }
    return sum;
}


int minEatingSpeed(int* piles, int pilesSize, int h) {
    int mid,low = 1,hour,high=findMax(piles,pilesSize);
    while(low<high){
        mid = low+(high - low)/2;
        printf("\n mid = %d",mid);
        hour = hours(piles,pilesSize,mid);
        if(hour>h){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return high;
}



int main() {
    int piles[] = {30,11,23,4,20};
    int pilesSize = sizeof(piles) / sizeof(piles[0]);
    int h = 5;
    int result = minEatingSpeed(piles, pilesSize, h);
    printf("\n %d\n", result);
    return 0;
}


