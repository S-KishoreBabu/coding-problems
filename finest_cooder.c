#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int areAdjacent(int,int);

int matrix[3][3]={
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

void shuffleMatrix(){
    int i, j, count=0;
    if(count%2==0){
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if(j!=2){
                    matrix[i][j]=matrix[i][j+1];
                }
                else{
                    matrix[i][j]=matrix[i][0];
                }
            }
        }
    }
    else{
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if(i!=2){
                    matrix[i][j]=matrix[i+1][j];
                }
                else{
                    matrix[i][j]=matrix[0][j];
                }
            }
        }
    }
            
}



int areAdjacent( int a, int b) {
    int rows=3,cols=3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == a) {
                if ((i > 0 && matrix[i-1][j] == b) ||   
                    (i < rows-1 && matrix[i+1][j] == b) 
                    (j > 0 && matrix[i][j-1] == b) ||  
                    (j < cols-1 && matrix[i][j+1] == b)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


int totaltime(int *nums,int numsSize){
    int sum=1;
    for(int i=0;i<numsSize-1;i++){
        if(nums[i]!=nums[i+1]){
            if(areAdjacent(nums[i],nums[i+1])){
                sum++;
            }
            else{
                sum+=2;
            }
        }
        shuffleMatrix();
    }
    return sum;
}

int main(){
    int nums[] = {2,2,3,2,2,8};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    system("cls");
    printf("%d\n",totaltime(nums,numsSize));
    return 0;
}