// * Not completed - leetcode - 2

#include<stdlib.h>
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2);
void printList(struct ListNode* head);
struct ListNode* createList(int arr[], int size);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    unsigned long numberValue(struct ListNode* list){
        unsigned long long sum = 0;
        unsigned long long k = 1;
        void merge(int val){
            sum+=(val*k);
            printf("\n -> %lld\n",sum);
            k*=10;
        }
        struct ListNode* temp = list;
        while(temp!=NULL){
            merge(temp->val);
            temp = temp -> next;
        }
        printf("\n value : %lld\n",sum);
        return sum;
    }

    unsigned long long sum = numberValue(l1)+numberValue(l2),temp = sum,t,count=0;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    void append(int x){
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = x;
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            tail = head;
        }
        else{
            tail->next = newnode;
            tail= tail->next;
        }
    }


    while(temp!=0){
        count++;
        temp/=10;
    }
    for(int i = 0;i<count;i++){
        t = sum % 10;
        append(t);
        sum/=10;
    }
    return head;
}

struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2){  // TODO : Need to complete here for above 30 digit number input
    while(l1 !=NULL && l2 != NULL){
        int a=0, b=0;
        while(l1!=NULL){
            l1 = l1->next;
        }
    }
}




int main() {
    // Example input: 342 (represented as 2 -> 4 -> 3) and 465 (5 -> 6 -> 4)
    int arr1[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    int arr2[] = {5,6,4};
    
    struct ListNode* l1 = createList(arr1, 31);
    struct ListNode* l2 = createList(arr2, 3);
    
    printf("First List: ");
    printList(l1);
    printf("Second List: ");
    printList(l2);
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("\n Sum List: ");
    printList(result);
    
    return 0;
}

struct ListNode* createList(int arr[], int size) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    for (int i = 0; i < size; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to print a linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}
