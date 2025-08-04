#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode node;
struct ListNode* swapNodes(struct ListNode* head, int k) {
    node*temp = head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int l = (count-k)+1;
    if(k>count/2){
        int z = k;
        k=l;
        l=z;
    }
    node* A;
    node* B;
    temp = head;
    int current =1;
    while(temp!=NULL){
        if(current==k){
            A = temp;
        }
        if(current == l){
            B = temp;
        }
        current++;
        temp = temp->next;
    }
    int j = A->val;
    A->val=B->val;
    B->val = j;
    return head;
}
int main() {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = NULL;
    // head->next->next->val = 3;
    // head->next->next->next = malloc(sizeof(struct ListNode));
    // head->next->next->next->val = 4;
    // head->next->next->next->next = malloc(sizeof(struct ListNode));
    // head->next->next->next->next->val = 5;
    // head->next->next->next->next->next = NULL;

    int k = 2;
    struct ListNode* result = swapNodes(head, k);

    while (result) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");

    return 0;
}
