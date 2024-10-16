#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int front=-1,rear=-1,item,i,q[10],choice;
int insert();
int delete();
int display();
int main()
{while(1)
{
    printf("1.Insert\n 2.delete\n 3.display\n 4.exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the element to insert:");
               scanf("%d",&item);
               insert();
               break;
        case 2:item=delete();
               if(item!= -1)
               { 
                printf("Deleted element =%d",item);
                break;
               } 
        case 3 :display();
                 break;
        case 4 : exit(0);
        default: printf("It is an invalid choice\n");
                 break;
     }
}}
int insert()
{
    if(front==MAX-1)
    {
    printf("Queue is full\n");
    return;
 
}
if(rear==-1 && front==-1)
{   front=0;
    rear=0;
}
else
{  
     rear=rear+1;
}  q[rear]=item;
}

int delete()
{
    if(front==-1 && rear==-1)
   { printf("Queue is empty\n");
    return -1;
   }
   item=q[front];
   if(front==rear)
      {
        front=-1;
        rear=-1;
      }
    else
    {
        front=front+1;
        return item;
    }

}

int display()
{
    if(front==-1 && rear==-1)
       printf("Queue is empty");
    else
      {
         printf("Queue contents are:");
         for(i=front;i<=rear;i++)
         printf("%d",q[i]);
      }
      printf("\n");
}