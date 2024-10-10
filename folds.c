
// find the number of folds by 
#include<stdio.h>
#include<stdlib.h>

int main(){
    int h=127,w=113,th=5,tw=4;
    int hf=0;
    int cut;

    while(h>th){
        if((h/2)>th){
            cut=h/2;
        }
        else{
            cut=th-h;
        }
        printf("\n cut = %d",cut);
        h=h-cut;
        hf=hf+1;
    }

    printf("\n HF : %d",hf);
}