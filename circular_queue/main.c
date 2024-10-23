#include <stdio.h>
#include <stdlib.h>
#define n 5
void insert(int q[], int *front, int *rear, int item)
{
    if(*front== -1 && *rear== -1){
        *front=0;
        *rear=0;
        q[*rear]=item;
        printf("\nSuccessfully inserted %d",item);
    }
    else if(*front==(*rear+1)%n){
        printf("\n Queue Overflow");
    }
    else{
        *rear=(*rear+1)%n;
        q[*rear]=item;
        printf("\nSuccessfully inserted %d",item);
    }
}
void delete(int q[], int *front, int *rear)
{
    if(*front== -1 && *rear== -1){
         printf("\n Queue Underflow");
    }
    else if(*front== 0 && *rear== 0){
        printf("\n Deleted item %d",q[*front]);
        *front=*rear= -1;
    }
    else{
        printf("\n Deleted item %d",q[*front]);
        *front=(*front + 1)%n;
    }
}
void display(int q[], int *front, int *rear)
{
    int i= *front;
    if(*front == -1 && *rear== -1){
        printf("\n Queue is Empty");
    }
        while (1) {
        printf("item %d : %d\n", (i + 1), q[i]);
        if (i == *rear) {
            break;
        }
        i = (i + 1) % n;
    }

}
int main()
{
    int q[n];
    int front=-1;
    int rear=-1;
    int choice;
    int item;
    while(1)
{
    printf("\n");
    printf("1.Insert\n2.delete\n3.display\n4.exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the element to insert:");
            scanf("%d",&item);
            insert(q,&front,&rear,item);
            break;
        case 2:
            delete(q,&front,&rear);
            break;
        case 3 :
            display(q,&front,&rear);
            break;
        case 4 :
            exit(0);
        default:
            printf("It is an invalid choice\n");
            break;
     }
}}
