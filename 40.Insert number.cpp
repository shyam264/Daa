#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a number into the list
Node* insert(Node* head, int number) {
    // Create a new node for the number
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    newNode->data = number;
    newNode->next = NULL;

    // If the list is empty, the new node becomes the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Otherwise, traverse to the end of the list and insert the new node
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

// Function to print the list
void printList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int number;

    // Input numbers to be inserted into the list
    printf("Enter numbers to insert into the list (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &number);
        if (number == -1) {
            break;
        }
        head = insert(head, number);
    }

    // Print the final list
    printList(head);

    // Free memory allocated for the list nodes
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
