// sum of minimum possible combination using pseudobinary number

#include<stdio.h> // completed
#include<math.h>

void Pseudobinary(int num){
    int x,y,no,k,pv;
    while (num!=0){
        y=0;
        no = num;
        k=0;
        pv=1;
        while(no!=0){
            x = no%10;
            if(x>0){
                y=1*pv+y;
            }
            else{
                y=0*pv+y;
            }
            no = no/10;
            k=(k*10)+1;
            pv = pv *10;
        }
        printf("%d + ",y);
        num = num-y;
    }
}
int main(){
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    Pseudobinary(n);
    return 0;
}