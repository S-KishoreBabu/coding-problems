#include <stdio.h>
#include<stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int*arr = (int*)malloc(sizeof(int)*(nums1Size+nums2Size));
    int top = -1,a = 0,b = 0,index; 
    while(a!=nums1Size && b!=nums2Size){
        if(nums1[a] <= nums2[b]){
            arr[++top] = nums1[a++];
        }
        else if(nums2[b] <= nums1[a] ){
            arr[++top] = nums2[b++];
        }
    }
    if(a==nums1Size){
        while(b!=nums2Size){
            arr[++top] = nums2[b++];
        }
    }
    else{
        while(a!=nums1Size){
            arr[++top] = nums1[a++];
        }  
    }
    index = top/2;
    return (top%2 == 0)?arr[top/2]:(double)(arr[index]+arr[index+1])/2;
}

int main() {
    int nums1[] = {3};
    int nums2[] = {-2,-1};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("\n res = %lf\n", result);

    return 0;
}
