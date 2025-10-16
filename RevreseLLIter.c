#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

struct Node* reverseIterative(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;        
    }
    
    return prev; 
}

int main() {
    int count, i;
    printf("Enter the count to be taken:");
    scanf("%d", &count);
    printf("Enter %d values:\n",count);
    struct Node* head = NULL;
    struct Node* temp = NULL;
    
    for (i = 0; i < count; i++) {
        int data;
        scanf("%d", &data);
        struct Node* new_node = newNode(data);
        
        if (head == NULL) {
            head = new_node;
            temp = new_node; 
        } else {
            temp->next = new_node;
            temp = new_node;
        }
    }
    
    
    head = reverseIterative(head);
    printList(head);
    
    return 0;
}

