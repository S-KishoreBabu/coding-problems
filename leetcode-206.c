#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode node;
struct ListNode* reverseList(struct ListNode* head) {
    int stack[10000];
    int top = -1;
    node*temp = head;
    while(temp!=NULL){
        stack[++top] = temp->val;
        temp= temp->next;
    }
    temp = head;
    for(int i =top;i>-1;i--){
        temp->val = stack[i];
        temp=temp->next;
    }
    return head;
}

int main() {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = NULL;

    struct ListNode* result = reverseList(head);

    while (result) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");

    return 0;
}
