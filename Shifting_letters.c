int maxScore(char* s) {
    int n = strlen(s);
    int sum,split,max=0;
    for(int i = 0;i<n-1;i++){
        split=i+1;
        sum=0;
        for(int j=0;j<n;j++){
            if(j<split){
                if(s[j]=='0'){sum++;}
            }else{
                if(s[j]=='1'){sum++;}
            }
        }
        if(sum==n){return sum;}
        if(sum>max){max=sum;}
    }
    return max;
}
