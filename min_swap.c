#include <stdio.h>// completed
#include <math.h>
#include <stdlib.h>
#include <string.h>

void findMinSwap(char *arr1, char *arr2, int size) {
    int swap = 0;
    for (int i = size - 1; i > 0; i--) {
        int a = (arr1[i - 1] - '0') * 10 + (arr1[i] - '0');
        int b = (arr2[i - 1] - '0') * 10 + (arr2[i] - '0');
        int c = (arr1[i - 1] - '0') * 10 + (arr2[i] - '0');
        int d = (arr2[i - 1] - '0') * 10 + (arr1[i] - '0');

        printf("\nComparing pairs:\n");
        printf(" a = %d, b = %d \n c = %d, d = %d\n", a, b, c, d);
        printf(" |a - b| = %d, |c - d| = %d\n", (a - b), (c - d));

        // Check if a swap is needed based on the differences
        // if ((a - b < 0 && c - d > 0) || (a - b > 0 && c - d < 0)) {
        //     if (abs(a - b) == abs(c - d)) {
        //         swap++;
        //         printf("Swap condition met: Swapping pairs a-b and c-d\n");
        //     }
        // } else if (abs(a - b) > abs(c - d)) {
        //     swap++;
        //     printf("Smaller difference found: Swapping to minimize difference\n");
        // }

        if ((a - b) > (c - d)) {
            swap++;
            printf("Smaller difference found: Swapping to minimize difference\n");
        }
    }
    printf("\nTotal number of swaps needed: %d\n", swap);
}

int main() {
    char arr1[] = "97567";//30124
    char arr2[] = "34123";//24897
    int size = strlen(arr1);
    findMinSwap(arr1, arr2, size);
    return 0;
}
