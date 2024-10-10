#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[]={1,2,3,4,5,7,9};
    int b[]={1,3,4,50,60};

    int s1=0,s2=0,n1,n2;
    n1=sizeof(a)/sizeof(a[0]);
    n2=sizeof(b)/sizeof(b[0]);
    // printf("\n s1 = %d <---> s2 = %d",s1,s2);
    while(s1<n1 && s2<n2){
        if(a[s1]==b[s2]){
            printf("%d %d ",a[s1],b[s2]);
            s1=s1+1;
            s2=s2+1;
            // printf("\n s1 = %d <---> s2 = %d",s1,s2);
        }
        else if(a[s1]<b[s2]){
            printf("%d ",a[s1]);
            s1=s1+1;
            // printf("\n s1 = %d <---> s2 = %d",s1,s2);
        }
        else{
            printf("%d ",b[s2]);
            s2=s2+1;
            // printf("\n s1 = %d <---> s2 = %d",s1,s2);
        }
    }
    if(s1<n1){
        while(s1<n1){
            printf("%d ",a[s1]);
            s1=s1+1;
        }
    }
    if(s2<n2){
        while(s2<n2){
            printf("%d ",b[s2]);
            s2=s2+1;
        }
    }

    return 0;
}