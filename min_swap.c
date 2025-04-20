#include<stdio.h>
#include<stdlib.h>

void swap(int*,int*,int*,int*);
void display();

int arr[3][3]= {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};
int n = 3;

void rotate(){
    for(int i = 0;i<n/2;i++){
        for(int j = 0;j<(n + 1)/2;j++){
            int temp = arr[i][j];
            arr[i][j] = arr[(n-1)-j][i];
            arr[(n-1)-j][i] = arr[(n-1)-i][(n-1)-j];
            arr[(n-1)-i][(n-1)-j] = arr[j][(n-1)-i];
            arr[j][(n-1)-i]= temp;
        }
    }
}

void display(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(){
    display();
    rotate();
    display();
    return 0;
}