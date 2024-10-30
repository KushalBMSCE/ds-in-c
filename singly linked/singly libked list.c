#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
};
void insertAtBeginning(struct Node** head, int data)
{
    struct Node* newNode=createNode(data);
    newNode->next= *head;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int data)
{
    struct Node* newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    else{
        struct Node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void insertAtPosition(struct Node** head, int data, int position)
{
    struct Node* newNode=createNode(data);
    if (position==1)
    {
        newNode->next= *head;
        *head=newNode;
        return;
    }
    struct Node* temp= *head;
    for(int i=1;i<position-1 && temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if (temp==NULL){
        printf("\nPositions out of bounds");
        free(newNode);
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void deleteAtBeginning(struct Node** head)
{
    if(*head==NULL)
    {
        printf("\nList is empty");
        return;
    }
    struct Node* temp= *head;
    *head = (*head)->next;
    free(temp);
}
void deleteAtEnd(struct Node** head)
{
    if(*head==NULL)
    {
        printf("\nList is empty");
        return;
    }
    struct Node* temp= *head;
    struct Node* prev=NULL;
    if((temp->next)==NULL)
    {
        *head=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void deleteAtPosition(struct Node** head, int position)
{
    struct Node* temp= *head;
    struct Node* prev=NULL;
    if(*head==NULL)
    {
        printf("\nList is empty");
        return;
    }
    else if(position == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for(int i=1;i<position && temp!=NULL;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    if (temp == NULL) {
        printf("\nPosition out of bounds\n");
        return;
    }
    prev->next=temp->next;
    free(temp);
}
void display(struct Node**head)
{
    if(*head==NULL)
    {
        printf("\nList is empty");
        return;
    }
    struct Node* temp= *head;
    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp=temp->next;
    }
}

void main()
{
    struct Node* head=NULL;
    int data;
    int position;
    int choice;
    while(1){
        printf("\n1.Insert at beginnng \n2.Insert at End \n3.Insert at position \n4.Delete at beginning \n5.Delete at End \n6.Delete at position \n7.Display list \nEnter choice");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the data to insert");
            scanf("%d",&data);
            insertAtBeginning(&head,data);
            break;
        case 2:
            printf("Enter the data to insert");
            scanf("%d",&data);
            insertAtEnd(&head,data);
            break;
        case 3:
            printf("Enter the data to insert");
            scanf("%d",&data);
            printf("Enter the position to insert");
            scanf("%d",&position);
            insertAtPosition(&head,data,position);
            break;
        case 4:
            deleteAtBeginning(&head);
            break;
        case 5:
            deleteAtEnd(&head);
            break;
        case 6:
            printf("Enter the position to delete");
            scanf("%d",&position);
            deleteAtPosition(&head,position);
            break;
        case 7:
            display(&head);
            break;
        default :
            printf("Invalid choice");
        }
    }
}
