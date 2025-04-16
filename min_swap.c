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

void swap(int *a,int *b,int *c,int *d ){
    int temp = *a;
    *a = *d;
    *d = *c;
    *c = *b;
    *b = temp;
}

void migrate(int i, int j){
    swap(
        &arr[i][j],
        &arr[j][(n-1)-i],
        &arr[(n-1)-i][(n-1)-j],
        &arr[(n-1)-j][i]
    );
}
void rotate(){
    for(int i = 0;i<n/2;i++){
        for(int j = 0;j<(n + 1)/2;j++){
            migrate(i,j);
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