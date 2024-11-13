#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nPosition out of bounds");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if ((temp->next) == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deleteAtPosition(struct Node** head, int position) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (*head == NULL) {
        printf("\nList is empty");
        return;
    } else if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nPosition out of bounds\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty");
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL) {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}


void sortList(struct Node** head) {
    if (*head == NULL) return;
    struct Node* i = *head;
    while (i != NULL) {
        struct Node* j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}


void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}


void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head2;
}

void main() {
    struct Node* head = NULL;
    struct Node* head2 = NULL;
    int data, position, choice;

    while (1) {
        printf("\n1. Insert at beginning \n2. Insert at end \n3. Insert at position \n4. Delete at beginning");
        printf("\n5. Delete at end \n6. Delete at position \n7. Display list \n8. Sort list");
        printf("\n9. Reverse list \n10. Concatenate another list \n11. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                display(&head);
                break;
            case 8:
                sortList(&head);
                printf("List sorted.\n");
                break;
            case 9:
                reverseList(&head);
                printf("List reversed.\n");
                break;
            case 10:
                printf("Enter 5 elements for the second list: ");
                for(int i=0; i<5; i++){
                    scanf("%d", &data);
                    insertAtEnd(&head2, data);
                }
                concatenateLists(&head, &head2);
                printf("Lists concatenated.\n");
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
