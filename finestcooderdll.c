#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node node;
struct Node* reverseDLLInGroups(struct Node* head, int k){
    node*temp = head;
    node*prev = NULL;
    node*start;
    node*end;
    node*result = NULL;
    while(temp!=NULL){
        end = temp;
        for(int i = 0;i < k && temp!=NULL; i++){
            printf("\n temp : %d",temp->data);
            temp->prev = temp->next;
            temp->next = prev;
            prev = temp;
            temp = temp ->prev;
        }
        start = prev;
        start->prev = end ->next;
        end->next = temp;
        prev = end;
        if(!result){
            result = start;
        }
        // display(result);
        for(node* it = start; it!=end->next; it=it->next){
            printf(" %d ",it->data);
        }
    }
    printf("\n -> %d\n ",result->data);
    return result;
}

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    int k = 3;

    struct Node* result = reverseDLLInGroups(head, k);

    struct Node* curr = result;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}
