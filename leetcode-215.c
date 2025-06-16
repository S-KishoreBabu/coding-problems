#include <stdio.h>

void display(int*, int);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    // Step 1: Build Max Heap
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }
    printf("\n\n heapified : \n");
    display(arr,n);

    for (int i = n-1; i >= 2; i--) {
        swap(&arr[1], &arr[i]);  // Move max to end
        heapify(arr, i, 1);  // Heapify reduced heap
    }
    printf("\n\n sorted : \n");
    display(arr,n);
}


int findKthLargest(int* nums, int numsSize, int k) {
    int size = numsSize+1;
    int arr[size];
    arr[0] = 0;
    for(int i = 1;i<size;i++){
        arr[i] = nums[i-1];
    }
    heapSort(arr,size);
    return arr[numsSize - k + 1];
}

void display(int *nums, int n){
    printf("\n\n ");
    for(int i = 0;i<n;i++){
        printf("%d ",nums[i]);
    }
}

int main() {
    int nums[] = {4,5,1,3,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 5;

    int result = findKthLargest(nums, numsSize, k);
    printf("\n\n%d\n", result);

    return 0;
}
