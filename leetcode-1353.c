#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int** arr, int low, int high) {
    int pivot = arr[high][1]; // Choosing the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j][1] <= pivot) {
            i++;
            swap(&arr[i][1], &arr[j][1]);
            swap(&arr[i][0], &arr[j][0]);
        }
    }
    // Swap pivot to correct position
    swap(&arr[i + 1][1], &arr[high][1]);
    swap(&arr[i + 1][0], &arr[high][0]);
    return i + 1;
}

// Quick Sort function
void quickSort(int** arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  // Sort before partition
        quickSort(arr, pi + 1, high); // Sort after partition
    }
}
 
void display(int** events, int eventsSize, int * eventsColSize){
    for(int i = 0;i<eventsSize; i++){
        printf("\n\n %d | %d",events[i][0],events[i][1]);
    }
}

int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    quickSort(events,0,eventsSize-1);
    int i = 0,j = 0,count = 0;
    while(i<eventsSize){
        while(j<events[i][0]){
            j++;
        }
        if(events[i][0]<= j && j <=events[i][1]){
            count++;
            j++;
            i++;
        }
    }
    return count;
}

int main() {
    int data[5][2] = {
        {1, 4},
        {4, 4},
        {2, 2},
        {3, 4},
        {1, 1}
    };

    int* events[5];
    for (int i = 0; i < 5; i++) events[i] = data[i];

    int eventsColSize[] = {2, 2, 2, 2, 2};
    int eventsSize = 5;

    int result = maxEvents(events, eventsSize, eventsColSize);
    printf("\n\n Res : %d\n", result);

    return 0;
}

