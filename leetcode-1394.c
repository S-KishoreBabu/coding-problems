#include <stdio.h>

int findLucky(int* arr, int arrSize) {
    int hash[1000];
    for(int i = 0;i<1000;i++){
        hash[i]=0;
    }
    for(int i = 0;i<arrSize;i++){
        hash[arr[i]]++;
    }
    int stack[100];
    int top = -1;
    for(int i = 1;i<1000;i++){
        if(hash[i]==i){
            stack[++top] = i;
        }
    }
    return (top!=-1)?stack[top]:-1;
}

int main() {
    int arr[] = {2, 2, 3, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int result = findLucky(arr, arrSize);
    printf("\n res : %d\n", result);

    return 0;
}
