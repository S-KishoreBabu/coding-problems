//Completed-sum of second while typing the number
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TABLE_SIZE 10

typedef struct lNode{
    int key;
    int data;
    struct lNode *next;
};

struct lNode *hashTable[TABLE_SIZE];

typedef struct lode node;




int areAdjacent(int,int);
void display_matrix();

int matrix[3][3]={
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

void shuffleMatrix(){
    static int count = 0,temp;
    //count++; 
    if(count % 2 == 0){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(j != 2){
                    if(j==0){temp=matrix[i][j];}
                    matrix[i][j] = matrix[i][j + 1];
                } 
                else {
                    matrix[i][j] = temp;
                }
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(j != 2){
                    if(j==0 && i==0){temp=matrix[i][j];}
                    matrix[i][j] = matrix[i][j + 1];
                } else {
                    matrix[i][j] = matrix[i+1][0];
                    if(i==2 & j==2){matrix[i][j] = temp;}
                }
            }
        }
    }
}

int areAdjacent(int a, int b) {
    int rows = 3, cols = 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == a) {
                if ((i > 0 && matrix[i - 1][j] == b) ||   
                    (i < rows - 1 && matrix[i + 1][j] == b) || 
                    (j > 0 && matrix[i][j - 1] == b) ||  
                    (j < cols - 1 && matrix[i][j + 1] == b)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


// int areAdjacentHash(int a, int b) {
//     int rows = 3, cols = 3;
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             if (matrix[i][j] == a) {
//                 if ((i > 0 && matrix[i - 1][j] == b) ||   //up
//                     (i < rows - 1 && matrix[i + 1][j] == b) || //down
//                     (j > 0 && matrix[i][j - 1] == b) ||  //l
//                     (j < cols - 1 && matrix[i][j + 1] == b)) {r//ight
//                     return 1;
//                 }
//             }
//         }
//     }
//     return 0;
// }

void generate_hashMap(){
    int rows = 3, cols = 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == a) {
                if (i > 0 ){
                    pushmap(matrix[i][j],matrix[i-1][j]);
                } 
                if(i < rows - 1 ){
                    pushmap(matrix[i][j],matrix[i+1][j]);
                }
                if(j > 0 ){
                    pushmap(matrix[i][j],matrix[i][j-1]);
                } 
                if(j < cols - 1 ){
                    pushmap(matrix[i][j],matrix[i][j+1]);
                }
            }
        }
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}



void pushmap(int key_val, int val) {
    int hashIndex = hashFunction(key);
    node *newNode = (node *) malloc(sizeof(node));
    newNode->key = key_val;
    newNode->data = val;
    newNode->next = NULL;

    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = newNode;
    } else {
        node *temp = hashTable[hashIndex];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}




int totaltime(int *nums, int numsSize){
    int sum = 1;
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] != nums[i + 1]){
            if(areAdjacent(nums[i], nums[i + 1])){
                sum++;
            } else {
                sum += 2;
            }
        }
        //shuffleMatrix();
        //display_matrix();
    }
    return sum;
}

void display_matrix(){
    printf("\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int nums[] = {4,5,1,2,9,9,8};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    system("cls");
    printf("\n Total seconds = %d\n", totaltime(nums, numsSize));
    return 0;
}
