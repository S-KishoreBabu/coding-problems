#include <stdio.h>
#include <stdbool.h>

bool isValid(int , int);

int roomData[3][3] = {
    {1, 0, 2},
    {0, 0, 0},
    {1, 0, 1}
};

int roomSize = 3;
void search2(int *a, int *b){
    for(int i = 0; i < roomSize; i++){
        for(int j = 0; j < roomSize; j++){
            if(roomData[i][j] == 2){
                *a=i;
                *b = j;
                break;
            }
        }
    }
}


void run(int i, int j,int *c){
    roomData[i][j] = 2;
    *c = *c + 1;
    if(isValid(i-1,j)) run(i-1,j,c);
    if(isValid(i+1,j)) run(i+1,j,c);
    if(isValid(i,j-1)) run(i,j-1,c);
    if(isValid(i,j+1)) run(i,j+1,c);
}

bool isValid(int i , int j){
    if(i<0 || i >= roomSize || j<0 || j>=roomSize || roomData[i][j] == 1 || roomData[i][j] == 2){
        return false;
    }
    return true;
}


int main(){
    int i,j,count = -1;
    search2(&i,&j);
    run(i,j,&count);
    printf("\n final Count = %d ",count);
    return 0;
}