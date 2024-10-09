#include<stdio.h>
#include<stdlib.h>

int main(){
    int data[]={4,4,6,2,5};
    int pta=2;
    int ptb=3;;
    int sumb=0;
    for(int i=0;i<5;i++){
        sumb+=ptb*data[i];
    }
    int suma=0;
    int t=sumb;
    int time;
    while(sumb!=0){
        if(abs(sumb-suma)<t){
            t=abs(sumb-suma);
            time=sumb+suma;
        }
        sumb-=ptb;
        suma+=pta;
    }
    printf("\n Minimum time is : %d",time);
    return 0;
}