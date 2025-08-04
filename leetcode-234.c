#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode node;

bool isPalindrome(struct ListNode* head) {
    int count = 0;
    int stack[10000];
    int top = -1;
    node*temp = head;
    while(temp!=NULL){
        stack[++top] = temp->val;
        temp= temp->next;
        count++;
    }
    temp = head;
    int n;
    if(count%2 == 0){
        n = count/2;
    }
    else{
        n = (count/2)+1;
    }
    for(int i = top;i>= n;i--){
        if(stack[i]!=temp->val){
            return false;
        }
        temp = temp->next;
    }
    return true;
}

int main() {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 1;
    head->next->next->next =NULL;
    // head->next->next->next = malloc(sizeof(struct ListNode));
    // head->next->next->next->val = 1;
    // head->next->next->next->next = NULL;

    bool result = isPalindrome(head);
    printf("%s\n", result ? "true" : "false");

    return 0;
}
