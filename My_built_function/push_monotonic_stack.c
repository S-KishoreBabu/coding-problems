// * Push the value in Decreasing Monotonic stack

void push(int val){
    while(top!=-1 && stack[top]<=val){
        top--;
    }
    stack[++top]=val;
}