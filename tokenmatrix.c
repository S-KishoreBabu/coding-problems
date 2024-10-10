#include<stdio.h>//completed
#include<stdlib.h>
#include<stdlib.h>

int main(){
    int arr[6][3]={
        {0,1,1},
        {0,2,2},
        {1,1,5},
        {1,2,6},
        {0,3,1},
        {1,3,3}
    };
    int elimit=4;
    int rows = 6;  

    int tn,val,N;

    for(int i = 0;i<rows;i++){
        for(int j=0;j<3;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int tokens = arr[0][1];
    for (int i = 1; i < rows; i++) {
        if (arr[i][1] > tokens) {
            tokens = arr[i][1];
        }
    }

    N = arr[0][2]+elimit;  
    for (int i = 1; i < rows; i++) {
        if (arr[i][2]+elimit > N) {
            N= arr[i][2]+elimit;
        }
    }
    // printf("\n No. of token : %d",tokens);
    // printf("\n No. of values : %d\n",N);

    int t1[tokens][N];

    for(int i=0;i<rows;i++){
        if(arr[i][0]==0){//store
            tn=arr[i][1];
            val=arr[i][1];
            for(int k=arr[i][2]-1;k<arr[i][2]+4;k++){
                t1[tn][k]=val;
                // printf("\n%d -> %d",k,val);
            }
        }
        else{//reset
            tn=arr[i][1];
            val=arr[i][2]-1;
            // printf("\n tn[%d][%d] ",tn,val);
            if(t1[tn][val]==tn){
               for(int k=arr[i][2]-1;k<arr[i][2]+4;k++){
                    t1[tn][k]=val;
                    //printf("\n%d -> %d",k,val);
                } 
                printf("\n token %d is active",tn);
            }
            else{
                printf("\n token %d is inactive",tn);
            }
        }
    }
    
    return 0;
}