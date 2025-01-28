#include<stdio.h>
#include<stdlib.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int* result = (int*)malloc(pricesSize * sizeof(int));
    int stack[pricesSize];
    int top = -1;

    for (int i = 0; i < pricesSize; i++) {
        while (top != -1 && prices[stack[top]] >= prices[i]) {
            result[stack[top]] = prices[stack[top]] - prices[i];
            top--;
        }
        stack[++top] = i;
    }

    while (top != -1) {
        result[stack[top]] = prices[stack[top]];
        top--;
    }

    *returnSize = pricesSize;
    return result;
}

int main() {
    int prices[] = {8, 4, 6, 2, 3};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    int returnSize;

    int* finalPricesArray = finalPrices(prices, pricesSize, &returnSize);
    printf("Final Prices: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", finalPricesArray[i]);
    }
    printf("\n");

    free(finalPricesArray); // Free the allocated memory
    return 0;
}
