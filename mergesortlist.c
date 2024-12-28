#include <stdio.h> //completed
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} node;

// Function to create a new node
node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list from user input
node* createList(int size) {
    if (size <= 0) return NULL;

    int value;
    printf("Enter the value for node 1: ");
    scanf("%d", &value);
    node* head = createNode(value);
    node* current = head;

    for (int i = 2; i <= size; i++) {
        printf("Enter the value for node %d: ", i);
        scanf("%d", &value);
        current->next = createNode(value);
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void printList(node* head) {
    node* current = head;
    while (current) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists
node* mergeTwoLists(node* list1, node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    node* head, * tail;

    if (list1->val < list2->val) {
        head = tail = list1;
        list1 = list1->next;
    } else {
        head = tail = list2;
        list2 = list2->next;
    }

    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;

    return head;
}

int main() {
    int size1, size2;

    printf("Enter the number of nodes in the first list: ");
    scanf("%d", &size1);
    printf("Creating the first list:\n");
    node* list1 = createList(size1);

    printf("Enter the number of nodes in the second list: ");
    scanf("%d", &size2);
    printf("Creating the second list:\n");
    node* list2 = createList(size2);

    printf("\nFirst List: ");
    printList(list1);

    printf("Second List: ");
    printList(list2);

    node* mergedList = mergeTwoLists(list1, list2);

    printf("\nMerged List: ");
    printList(mergedList);

    return 0;
}
