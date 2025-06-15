// * display the stack Values

void displayStack(){
    printf("\n\n");
    for(int i = top; i>= 0; i--){
        printf(" %d \n ",stack[i]);
    }
}